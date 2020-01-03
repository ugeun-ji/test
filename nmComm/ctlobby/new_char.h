#pragma once

#include "ctnet/handler.h"
#include "lobby_char.h"

namespace ctlobby
{
	class NewChar : public ctnet::Handler<Packet::Login::USNewChar, Packet::Login::LGNewChar>
	{
		IMPLEMENT_HANDLER_DUPLEX(NewChar, U2L_NEWCHAR, L2U_NEWCHAR)

		flatbuffers::Offset<RequestType> OnMarshal(PacketBuilder& builder, const FString& CharName, int32 Gender, int32 Hair, int32 ArmorSet)
		{
			auto char_name = builder.CreateString<std::string>(TCHAR_TO_UTF8(*CharName));
			auto gen = static_cast<int8_t>(Gender);
			auto hair = static_cast<int8_t>(Hair);
			auto armor_set = static_cast<int8_t>(ArmorSet);
			UE_LOG(LogComm, Verbose, TEXT("USNewChar char_name=%s gen=%d hair=%d armor_set=%d"), *CharName, gen, hair, armor_set);
			return Packet::Login::CreateUSNewChar(builder, char_name, gen, hair, armor_set);
		}

		void OnMessage(const MessageType* msg)
		{
			UE_LOG(LogComm, Verbose, TEXT("LGNewChar sid=%d name=%s gender=%d hair=%d checkpoint=%d w1=%d:%d w2=%d:%d w3=%d:%d a1=%d:%d a2=%d:%d a3=%d:%d a4=%d:%d")
				, msg->info()->sid()
				, UTF8_TO_TCHAR(msg->info()->charName()->c_str())
				, msg->info()->gender()
				, msg->info()->hair()
				, msg->info()->checkpoint()
				, msg->info()->weapon1(), msg->info()->w1tier()
				, msg->info()->weapon2(), msg->info()->w2tier()
				, msg->info()->weapon3(), msg->info()->w3tier()
				, msg->info()->armor1(), msg->info()->a1tier()
				, msg->info()->armor2(), msg->info()->a2tier()
				, msg->info()->armor3(), msg->info()->a3tier()
				, msg->info()->armor4(), msg->info()->a4tier());
			ctlobby::charlist().AddCharacter(msg->info());
			ctlobby::charlist().SetActivatedCharacter(msg->info()->sid());
		}
	};
}
