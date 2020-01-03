#include "nmNetPacket.h"

TSharedPtr<FnmNetPacket, ESPMode::ThreadSafe> FnmNetPacket::CreateFromBuffer(const void* Data, int32 DataSize)
{
	const uint8* pData = (const uint8*)Data;

	TSharedPtr<FnmNetPacket, ESPMode::ThreadSafe> NewPacket = MakeShareable(new FnmNetPacket());

	NewPacket->Type = *(uint16*)pData;
	pData += sizeof(uint16);

	NewPacket->Size = *(uint16*)pData;
	pData += sizeof(uint16);

	const int PayloadSize = DataSize - (pData - (const uint8*)Data);

	NewPacket->PayloadBuffer.AddUninitialized(PayloadSize);
	FMemory::Memcpy(NewPacket->PayloadBuffer.GetData(), pData, PayloadSize);

	return NewPacket;
}

FnmNetPacket::FnmNetPacket()
	: PayloadBufferIndex(0)
{}

FnmNetPacket::FnmNetPacket(uint16 InType)
	: Type(InType)
	, Size(0)
	, PayloadBufferIndex(0)
{
	Size += sizeof(Type);
	Size += sizeof(uint16);
}

void FnmNetPacket::Serialize(const void* InData, int32 InSize)
{
	PayloadBuffer.AddUninitialized(InSize);
	FMemory::Memcpy(PayloadBuffer.GetData() + PayloadBufferIndex, InData, InSize);
	PayloadBufferIndex += InSize;
	Size += InSize;
}

void FnmNetPacket::WriteToBuffer(TArray<uint8>& OutBuffer) const
{
	const int32 BufferSize = OutBuffer.Num();

	OutBuffer.AddUninitialized(sizeof(Type) + sizeof(Size) + GetPayloadSize());

	uint8* DataPtr = OutBuffer.GetData() + BufferSize;

	// write Type
	FMemory::Memcpy(DataPtr, &Type, sizeof(Type));
	DataPtr += sizeof(Type);

	// write Size
	FMemory::Memcpy(DataPtr, &Size, sizeof(Size));
	DataPtr += sizeof(Type);

	// write Payload
	FMemory::Memcpy(DataPtr, GetPayloadData(), GetPayloadSize());
}