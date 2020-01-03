#pragma once

#include "ctnet/handler.h"

namespace ctlobby
{
	class RemoveChar : public ctnet::Handler<Packet::Login::USRemoveChar, Client::Internal::Null>
	{
		IMPLEMENT_HANDLER_TX(RemoveChar, U2L_REMOVECHAR)

		flatbuffers::Offset<RequestType> OnMarshal(PacketBuilder& builder, int32 CharSID)
		{
			UE_LOG(LogComm, Verbose, TEXT("USRemoveChar CharSID=%d"), CharSID);
			return Packet::Login::CreateUSRemoveChar(builder, CharSID);
		}
	};
}