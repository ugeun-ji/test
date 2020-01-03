#pragma once

#include "ctnet/handler.h"

namespace ctgame
{
	class ServerAssign : public ctnet::Handler<Packet::Client::USAssignServer, Packet::Client::CTAssignServer>
	{
		IMPLEMENT_HANDLER_DUPLEX(ServerAssign, U2C_ASSIGN_SERVER, C2U_ASSIGN_SERVER)
		flatbuffers::Offset<RequestType> OnMarshal(PacketBuilder& builder, int32 DesiredServerID, int32 DesiredChannelID = 0, uint64 Hash = 0)
		{
			UE_LOG(LogComm, Verbose, TEXT("USAssignServer dsid=%d chid=%d hash=%llu"), DesiredServerID, DesiredChannelID, Hash);
			return Packet::Client::CreateUSAssignServer(builder, DesiredServerID, DesiredChannelID, Hash);
		}
	};
}