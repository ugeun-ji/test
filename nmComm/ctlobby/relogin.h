#pragma once

#include "ctnet/handler.h"
#include "ctnet/authenticator.h"

namespace ctlobby
{
	class Relogin : public ctnet::Handler<Packet::Login::USRelogin, Client::Internal::Null>
	{
		IMPLEMENT_HANDLER_TX(Relogin, U2L_RELOGIN)

		flatbuffers::Offset<RequestType> OnMarshal(PacketBuilder& builder)
		{
			auto uid = builder.CreateString<std::string>(TCHAR_TO_UTF8(*ctnet::authenticator().GetUserID()));
			auto token = builder.CreateString<std::string>(TCHAR_TO_UTF8(*ctnet::authenticator().GetToken()));
			UE_LOG(LogComm, Verbose, TEXT("USRelogin uid=%s token=%s"), *ctnet::authenticator().GetUserID(), *ctnet::authenticator().GetToken());
			return Packet::Login::CreateUSRelogin(builder, uid, token);
		}
	};
}