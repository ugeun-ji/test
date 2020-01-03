#pragma once

#include "ctnet/handler.h"
#include "lobby_char.h"

namespace ctlobby
{
	class CharList : public ctnet::Handler<Packet::Login::USCharList, Packet::Login::LGCharList>
	{
		IMPLEMENT_HANDLER_DUPLEX(CharList, U2L_CHARLIST, L2U_CHARLIST)

		flatbuffers::Offset<RequestType> OnMarshal(PacketBuilder& builder)
		{
			UE_LOG(LogComm, Verbose, TEXT("USCharList"));
			return Packet::Login::CreateUSCharList(builder);
		}

		void OnMessage(const MessageType* msg)
		{
			UE_LOG(LogComm, Verbose, TEXT("LGCharList count=%u"), msg->count());
			ctlobby::charlist().SetCharacterList(msg);
		}
	};
}