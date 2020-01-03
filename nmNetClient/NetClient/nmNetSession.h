#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"
#include "HAL/ThreadSafeBool.h"

class FnmNetConnection;
class FnmNetPacket;

typedef TSharedPtr<FnmNetPacket, ESPMode::ThreadSafe> FnmNetPacketPtr;

DECLARE_MULTICAST_DELEGATE_OneParam(FnmNetCallback, const FnmNetPacketPtr&)

class FnmNetSession : FRunnable
{
public:
	FnmNetSession(TSharedRef<FnmNetConnection> InConnection);
	~FnmNetSession();

public:
	bool StartReceiveThread();
	bool IsConnected() const;

	bool ReceiveData(const float MaxTime = 0);
	bool SendData(const void* Data, const int32 DataLen);

	NMNETCLIENT_API void SetPacketListener(FnmNetCallback::FDelegate Listener);
	NMNETCLIENT_API FDelegateHandle AddHandler(const uint16 Type, FnmNetCallback::FDelegate Delegate);
	void RemoveHandler(const uint16 Type, FDelegateHandle& InHandle);

	void SendPacket(const FnmNetPacket& Packet);
	void ReceivePacket(FnmNetPacketPtr Packet);
	void DispatchPacket();

	void Close() { Stop(); }

protected:
	// FRunnable overrides begin
	virtual uint32 Run() override;
	virtual void Stop() override;
	// FRunnable overrides end	

protected:
	TSharedPtr<FnmNetConnection> Connection;		
	TMap<uint16, FnmNetCallback> DispatchMap;
	TArray<FnmNetPacketPtr> ReceivedPackets;
	FnmNetCallback PacketListener;

	FThreadSafeBool ExitRequested;
	FThreadSafeBool IsRunning;

	FCriticalSection ReceiveMutex;
	FCriticalSection SendMutex;		
	FCriticalSection PacketMutex;

	double LastReceiveTime;
	double LastSendTime;
	double PingTime;
	bool HasErrorState;

	int32 ReceivedDataSize;
	int32 ExpectedDataSize;
	TArray<uint8> ReceiveBuffer;	
};

typedef TSharedPtr<FnmNetSession, ESPMode::ThreadSafe> FnmNetSessionPtr;