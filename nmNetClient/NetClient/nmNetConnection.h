#pragma once

#include "HAL/ThreadSafeBool.h"

class FSocket;

class FnmNetConnection : public TSharedFromThis<FnmNetConnection>
{
public:
	FnmNetConnection();
	virtual ~FnmNetConnection();

	bool Connect(const TCHAR* InEndPoint);
	bool Listen(const int16 Port);
	void Close();
	bool WaitForConnection(double InTimeout, TFunction<bool(TSharedRef<FnmNetConnection>)> InDelegate);
	int32 SendData(const void* InData, const int32 InSize);
	int32 ReceiveData(void* OutBuffer, const int32 BufferSize);
	bool IsConnected() const;
	bool IsListening() const;
	FString GetDescription() const;
	FSocket* GetSocket() { return Socket; }
	uint32 GetPacketsReceived() const;

private:
	void CloseWithError(const TCHAR* Error, FSocket* InSocket = nullptr);
	bool Attach(FSocket* InSocket);

	FThreadSafeBool IsAttemptingConnection;
	FCriticalSection SocketMutex;
	FSocket* Socket;
	bool IsListener;
	uint32 PacketsReceived;
};