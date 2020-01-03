#pragma once

#include "ctmsg/msg_COMMON.h"
#include "ctmsg/msg_CT.h"
#include "ctmsg/msg.h"
#include "ctnet/agent.h"
#include "ctnet/handler.h"
#include "exception.h"
#include "verification.h"
#include "server_list.h"
#include "server_assign.h"

namespace ctgame
{
	extern NMCOMM_API ctnet::Agent gameAgent;

	typedef ctnet::Context context;

	FORCEINLINE void connect(const FString& Addr, const TFunction<void(bool)>& PostFunc)
	{
		gameAgent.Connect(Addr, PostFunc);
	}

	FORCEINLINE void disconnect()
	{
		gameAgent.Disconnect();
	}

	FORCEINLINE bool isconnected()
	{
		return gameAgent.IsConnected();
	}

	template<typename T> FORCEINLINE T& handler()
	{
		return gameAgent.Handler<T>();
	}
}
