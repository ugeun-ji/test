#pragma once

#include "CoreMinimal.h"

class FnmNetPacket
{
public:
	FnmNetPacket();
	FnmNetPacket(uint16 InType);
	virtual ~FnmNetPacket() {}

	static TSharedPtr<FnmNetPacket, ESPMode::ThreadSafe> CreateFromBuffer(const void* Data, int32 DataSize);

	const uint16 GetPacketType() const { return Type; }
	const uint16 GetPacketSize() const { return Size; }
	const int32 GetPayloadSize() const { return PayloadBuffer.Num(); }
	const uint8* GetPayloadData() const { return PayloadBuffer.GetData(); }

	void Serialize(const void* InData, int32 InSize);
	void WriteToBuffer(TArray<uint8>& OutBuffer) const;	

protected:
	uint16 Type;
	uint16 Size;
	TArray<uint8> PayloadBuffer;
	int32 PayloadBufferIndex;
};

typedef TSharedPtr<class FnmNetPacket, ESPMode::ThreadSafe> FnmNetPacketPtr;