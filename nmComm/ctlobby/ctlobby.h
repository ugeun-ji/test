#pragma once

#include "ctmsg/msg_COMMON.h"
#include "ctmsg/msg_LOGIN.h"
#include "ctmsg/msg.h"
#include "ctnet/agent.h"
#include "ctnet/handler.h"
#include "exception.h"
#include "login.h"
#include "relogin.h"
#include "char_list.h"
#include "new_char.h"
#include "remove_char.h"

namespace ctlobby
{
	extern NMCOMM_API ctnet::Agent lobbyAgent;

	typedef ctnet::Context context;

	FORCEINLINE void connect(const FString& Addr, const TFunction<void(bool)>& PostFunc)
	{
		lobbyAgent.Connect(Addr, PostFunc);
	}

	FORCEINLINE void disconnect()
	{
		lobbyAgent.Disconnect();
	}

	FORCEINLINE bool isconnected()
	{
		return lobbyAgent.IsConnected();
	}

	template<typename T> FORCEINLINE T& handler()
	{
		return lobbyAgent.Handler<T>();
	}
}