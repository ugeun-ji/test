#pragma once

#include "CoreMinimal.h"

class FnmNetConnection;
class FnmNetSession;

typedef TSharedPtr<FnmNetSession, ESPMode::ThreadSafe> FnmNetSessionPtr;

DECLARE_MULTICAST_DELEGATE_OneParam(FnmNetClientDelegate, FnmNetSessionPtr&)
DECLARE_MULTICAST_DELEGATE_OneParam(FnmNetClientBoolDelegate, bool)

class NMNETCLIENT_API FnmNetClient
{
public:
	FnmNetClient(const TCHAR* InHostAddress);
	virtual ~FnmNetClient();

	void Tick(float DeltaTime);
	void Close();
	void CloseWithError(const FString& Msg);
	bool IsConnected() const;

	FnmNetClientDelegate OnSessionEstablished;
	FnmNetClientDelegate OnSessionClosing;
	FnmNetClientBoolDelegate OnSessionRejected;

	void SendPacket(const class FnmNetPacket* Packet);
	void SendPacket(uint16 Type, const uint8* PayloadData, uint32 PaylaodSize);

private:
	TSharedPtr<FnmNetConnection> Connection;
	FnmNetSessionPtr Session;

	FString HostAddress;
	bool IsConnecting;
    float ConnectionTimeout;
	double ConnectionAttemptTimer;
	double TimeConnectionAttemptStarted;

	FString ErrorMessage;

	void StartConnection();
	void CheckConnection();
};

typedef TSharedPtr<class FnmNetClient> FnmNetClientPtr;