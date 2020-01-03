#include "nmNetClient.h"
#include "nmNetConnection.h"
#include "nmNetSession.h"
#include "nmNetPacket.h"
#include "Sockets.h"

FnmNetClient::FnmNetClient(const TCHAR* InHostAddress)
	: HostAddress(InHostAddress)
	, IsConnecting(false)
	, ConnectionTimeout(5)
	, ConnectionAttemptTimer(FLT_MAX)
	, TimeConnectionAttemptStarted(0)	
{
	Close();
}

FnmNetClient::~FnmNetClient()
{
	Close();
}

void FnmNetClient::Close()
{
	if (Session.IsValid())
	{
		Session->Close();
		OnSessionClosing.Broadcast(Session);
	}

	Session = nullptr;
	Connection = nullptr;
}

void FnmNetClient::CloseWithError(const FString& Message)
{
	ErrorMessage = Message;	
	Close();	
}

bool FnmNetClient::IsConnected() const
{
	return Session.IsValid() && Session->IsConnected();
}

void FnmNetClient::Tick(float DeltaTime)
{
	if (false == Session.IsValid())
	{
		if (IsConnecting == false && ErrorMessage.Len() == 0)
		{
			const double TimeSinceLastAttempt = FPlatformTime::Seconds() - TimeConnectionAttemptStarted;
			if (TimeSinceLastAttempt >= 5.f)
			{
				StartConnection();
			}
		}
		if (IsConnecting)
		{
			CheckConnection();
		}
	}
	else
	{
		// Session is valid
		Session->DispatchPacket();

		// @nmTODO
		////if (!Session->IsConnected())
		////{
		////	FString Msg = TEXT("Disconnected by foreign host");
		////	CloseWithError(*Msg);
		////}
	}
}

void FnmNetClient::StartConnection()
{
	check(IsConnecting == false);
	Close();

	Connection = MakeShareable(new FnmNetConnection());
	if (Connection.IsValid())
	{
		if (Connection->Connect(*HostAddress))
		{
			IsConnecting = true;
			check(Connection->GetSocket());
		}
	}
	TimeConnectionAttemptStarted = FPlatformTime::Seconds();
}

void FnmNetClient::CheckConnection()
{
	check(false == Session.IsValid() && true == IsConnecting);
	check(Connection.IsValid() && Connection->GetSocket());

	bool Success = Connection->WaitForConnection(0, [this](auto InConnection) {
		int32 WantedSize = 4 * 1024 * 1024;
		int32 ActualSize = 0;

		InConnection->GetSocket()->SetReceiveBufferSize(WantedSize, ActualSize);

		Session = MakeShareable(new FnmNetSession(InConnection));
		Session->StartReceiveThread();

		IsConnecting = false;

		// do initial stuffs here...
		OnSessionEstablished.Broadcast(Session);

		return true;
	});

	const double TimeSpentConnecting = FPlatformTime::Seconds() - TimeConnectionAttemptStarted;
	if (!Session.IsValid())
	{
		if (Success == false || TimeSpentConnecting >= ConnectionTimeout)
		{
			IsConnecting = false;

			FString Msg;

			if (TimeSpentConnecting >= ConnectionTimeout)
			{
				Msg = FString::Printf(TEXT("Timeout connection attempt after %.02f seconds"), TimeSpentConnecting);
			}
			else
			{
				Msg = TEXT("Failed to check for connection. Aborting.");
			}

			UE_LOG(LogTemp, Log, TEXT("Error: %s"), *Msg);
			
			OnSessionRejected.Broadcast((TimeSpentConnecting >= ConnectionTimeout) ? true : false);

			CloseWithError(*Msg);

			TimeConnectionAttemptStarted = FPlatformTime::Seconds();
		}
	}
}

void FnmNetClient::SendPacket(const class FnmNetPacket* Packet)
{
	check(Session.IsValid() && !IsConnecting);
	Session->SendPacket(*Packet);
}

void FnmNetClient::SendPacket(uint16 Type, const uint8* PayloadData, uint32 PayloadSize)
{
	check(Session.IsValid() && !IsConnecting);
	FnmNetPacket Packet(Type);
	Packet.Serialize(PayloadData, PayloadSize);
	Session->SendPacket(Packet);
}