#pragma once

#include "ctnet/handler.h"

namespace ctgame
{
	class ServerList : public ctnet::Handler<Packet::Client::USServerList, Packet::Client::CTServerList>
	{
		IMPLEMENT_HANDLER_DUPLEX(ServerList, U2C_SERVER_LIST, C2U_SERVER_LIST)
		flatbuffers::Offset<RequestType> OnMarshal(PacketBuilder& builder, int32 Reserved)
		{
			UE_LOG(LogComm, Verbose, TEXT("USServerList Reserved=%d"), Reserved);
			return Packet::Client::CreateUSServerList(builder, Reserved);
		}
	};
}