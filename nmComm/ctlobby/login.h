#pragma once

#include "ctnet/handler.h"
#include "ctnet/authenticator.h"

namespace ctlobby
{
	class Login : public ctnet::Handler<Packet::Login::USLogin, Packet::Login::LGLogin>
	{
		IMPLEMENT_HANDLER_DUPLEX(Login, U2L_LOGIN, L2U_LOGIN)

		flatbuffers::Offset<RequestType> OnMarshal(PacketBuilder& builder, const FString& ID, const FString& Password)
		{
			auto str_id = builder.CreateString<std::string>(TCHAR_TO_UTF8(*ID));
			auto str_pw = builder.CreateString<std::string>(TCHAR_TO_UTF8(*Password));
			UE_LOG(LogComm, Verbose, TEXT("USLogin str_id=%s str_pw=%s"), *ID, *Password);
			return Packet::Login::CreateUSLogin(builder, str_id, str_pw);
		}

		void OnMessage(const MessageType* msg)
		{
			UE_LOG(LogComm, Verbose, TEXT("LGLogin code=[%d:%s]"), static_cast<int32>(msg->code()), UTF8_TO_TCHAR(Packet::Login::EnumNameLoginErrorCode(msg->code())));
			if (msg->code() == Packet::Login::LoginErrorCode::LoginErrorCode_Ok)
			{
				FString UserID = msg->userid()->c_str();
				FString Token = msg->token()->c_str();
				ctnet::authenticator().Clear();
				ctnet::authenticator().SetUserID(UserID);
				ctnet::authenticator().SetToken(Token);
			}
		}
	};
}