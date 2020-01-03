#include "nmNetSession.h"
#include "nmNetConnection.h"
#include "nmNetPacket.h"

#include "HAL/PlatformTime.h"
#include "HAL/PlatformProcess.h"
#include "Sockets.h"

DEFINE_LOG_CATEGORY_STATIC(LogNetClient, Log, All);

FnmNetSession::FnmNetSession(TSharedRef<FnmNetConnection> InConnection)
	: Connection(InConnection)
{
	LastReceiveTime = 0.f;
	LastSendTime = 0.f;
	PingTime = 3.f;
	HasErrorState = false;

	ExpectedDataSize = 0;
	ReceivedDataSize = 0;

	const int32 NetSession_DefaultBufferSize = 4096;
	ReceiveBuffer.AddUninitialized(NetSession_DefaultBufferSize);
}

FnmNetSession::~FnmNetSession()
{
	if (IsRunning)
	{
		Stop();
	}
}

bool FnmNetSession::StartReceiveThread()
{
	check(IsRunning == false);

	FRunnableThread* Thread = FRunnableThread::Create(this, TEXT("nmNetClient"), 1024 * 1024, TPri_AboveNormal);

	if (Thread)
	{
		IsRunning = true;
	}

	return Thread != nullptr;
}

uint32 FnmNetSession::Run()
{
	const float Timeout = 0;

	while (ExitRequested == false)
	{
		if (!ReceiveData(1))
		{
			HasErrorState = true;
			ExitRequested = true;
		}

		////if (PingEnabled)
		////{
		////	const float TimeSinceSend = FPlatformTime::Seconds() - LastSendTime;

		////	if (TimeSinceSend >= PingTime)
		////	{		
		////		// make ping message
		////		//SendPacket(Msg);
		////	}
		////}

		if (Timeout > 0)
		{
			const double TimeSinceActivity = (FPlatformTime::Seconds() - LastReceiveTime);
			if (TimeSinceActivity >= Timeout)
			{
				HasErrorState = true;
				ExitRequested = true;
			}
		}

		FPlatformProcess::SleepNoStats(0);
	}

	IsRunning = false;
	return 0;
}

void FnmNetSession::Stop()
{
	PacketListener.Clear();

	if (IsRunning)
	{
		ExitRequested = true;

		while (IsRunning)
		{
			FPlatformProcess::SleepNoStats(0.01);
		}
	}

	Connection = nullptr;
}

bool FnmNetSession::ReceiveData(const float MaxTime /*=0*/)
{
	FScopeLock Lock(&ReceiveMutex);

	const double StarTime = FPlatformTime::Seconds();

	Connection->GetSocket()->Wait(ESocketWaitConditions::WaitForRead, FTimespan(0, 0, MaxTime));

	const double ElapsedTime = FPlatformTime::Seconds() - StarTime;

	int32 Received = Connection->ReceiveData(ReceiveBuffer.GetData() + ReceivedDataSize, ReceiveBuffer.Num() - ReceivedDataSize);

	if (Received > 0)
	{	
		LastReceiveTime = FPlatformTime::Seconds();

		ReceivedDataSize += Received;

		UE_LOG(LogNetClient, VeryVerbose, TEXT("ReceivedData Received=%d, ReceivedDataSize=%d"), Received, ReceivedDataSize);

		const uint8* pData = (const uint8*)ReceiveBuffer.GetData();

		if (ReceivedDataSize < 4)
		{
			ExpectedDataSize = 4;
		}
		else
		{
			int16 Type = *(uint16*)(pData);
			int16 Size = *(uint16*)(pData + sizeof(uint16));

			ExpectedDataSize = Size;
		}

		while (ReceivedDataSize >= ExpectedDataSize)
		{
			int16 Type = *(uint16*)(pData);
			int16 Size = *(uint16*)(pData + sizeof(uint16));

			UE_LOG(LogNetClient, VeryVerbose, TEXT("ReceivedDataSize=%d Size=%d"), ReceivedDataSize, Size);

			if (ReceivedDataSize >= Size)
			{
				UE_LOG(LogNetClient, VeryVerbose, TEXT("Make Packet Type=%d Size=%d"), Type, Size);

				FnmNetPacketPtr Packet = FnmNetPacket::CreateFromBuffer(pData, Size);
				if (Packet.IsValid())
				{
					ReceivePacket(Packet);
				}

				ReceivedDataSize -= Size;
				pData += Size;
			}
			else
			{				
				UE_LOG(LogNetClient, VeryVerbose, TEXT("Expecting remained %d bytes"), Size - ReceivedDataSize);
			}
		}

		UE_LOG(LogNetClient, VeryVerbose, TEXT("Remained ReceivedDataSize=%d"), ReceivedDataSize);
	}
	else if (Received == 0)
	{
		// connection has been lost?
		//UE_LOG(LogNetClient, VeryVerbose, TEXT("ElapsedTime = %f"), ElapsedTime);
		if (ElapsedTime < KINDA_SMALL_NUMBER)
		{
			UE_LOG(LogNetClient, Warning, TEXT("Connection has been lost!!"));
			return false;
		}
	}

	return true;
}

bool FnmNetSession::SendData(const void* Data, const int32 DataLen)
{
	FScopeLock Lock(&SendMutex);

	if (!IsConnected())
	{
		return false;
	}

	// write size
	int32 Sent = 0;

	if (DataLen > 0)
	{
		////// send data length first
		////Connection->SendData(&DataLen, sizeof(DataLen));

		// send data
		Sent = Connection->SendData(Data, DataLen);

		LastSendTime = FPlatformTime::Seconds();
	}

	return Sent > 0;
}

bool FnmNetSession::IsConnected() const
{
	return Connection.IsValid() && Connection->IsConnected() && (HasErrorState == false);
}

void FnmNetSession::SetPacketListener(FnmNetCallback::FDelegate Listener)
{
	PacketListener.Add(Listener);
}

FDelegateHandle FnmNetSession::AddHandler(const uint16 Type, FnmNetCallback::FDelegate Delegate)
{
	FnmNetCallback& Callback = DispatchMap.FindOrAdd(Type);
	return Callback.Add(Delegate);
}

void FnmNetSession::RemoveHandler(const uint16 Type, FDelegateHandle& InHandle)
{
	FnmNetCallback& Callback = DispatchMap.FindChecked(Type);
	Callback.Remove(InHandle);
	InHandle.Reset();
}

void FnmNetSession::SendPacket(const FnmNetPacket& Packet)
{
	TArray<uint8> Data;
	Packet.WriteToBuffer(Data);
	SendData(Data.GetData(), Data.Num());
}

void FnmNetSession::ReceivePacket(FnmNetPacketPtr Packet)
{
	FScopeLock Lock(&PacketMutex);

	UE_LOG(LogNetClient, Verbose, TEXT("Receive packet type=%d, size=%d"), Packet->GetPacketType(), Packet->GetPacketSize());

	ReceivedPackets.Add(Packet);
}

void FnmNetSession::DispatchPacket()
{
	FScopeLock Lock(&PacketMutex);

	if (PacketListener.IsBound())
	{
		for (auto& Packet : ReceivedPackets)
		{
			UE_LOG(LogNetClient, Verbose, TEXT("Dispatch packet to listener / packet type=%d, size=%d"), Packet->GetPacketType(), Packet->GetPacketSize());
			PacketListener.Broadcast(Packet);
		}
	}
	else
	{
		for (auto& Packet : ReceivedPackets)
		{		
			const uint16 Type = Packet->GetPacketType();
			FnmNetCallback* pDispatchCallback = DispatchMap.Find(Type);
			if (pDispatchCallback)
			{
				UE_LOG(LogNetClient, Verbose, TEXT("Dispatch packet to callback map / packet type=%d, size=%d"), Packet->GetPacketType(), Packet->GetPacketSize());
				pDispatchCallback->Broadcast(Packet);
			}
			else
			{
				UE_LOG(LogNetClient, Verbose, TEXT("Dispatch packet failed / packet type=%d, size=%d"), Packet->GetPacketType(), Packet->GetPacketSize());
			}
		}
	}

	ReceivedPackets.Empty();
}