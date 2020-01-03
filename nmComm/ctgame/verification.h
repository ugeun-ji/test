#pragma once

#include "ctnet/handler.h"

namespace ctgame
{
	class Verification : public ctnet::Handler<Packet::Client::USVerification, Client::Internal::Null>
	{
		IMPLEMENT_HANDLER_TX(Verification, U2C_VERIFICATION)

		flatbuffers::Offset<RequestType> OnMarshal(PacketBuilder& builder, const FString& InUserID, const FString& InToken)
		{
			auto userid = builder.CreateString<std::string>(TCHAR_TO_UTF8(*InUserID));
			auto token = builder.CreateString<std::string>(TCHAR_TO_UTF8(*InToken));
			UE_LOG(LogComm, Verbose, TEXT("USVerification userid=%s token=%s"), *InUserID, *InToken);
			return Packet::Client::CreateUSVerification(builder, userid, token);
		}
	};
}