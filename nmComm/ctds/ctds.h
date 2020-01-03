#pragma once

#include "ctmsg/msg_COMMON.h"
#include "ctmsg/msg_CT.h"
#include "ctmsg/msg.h"
#include "ctnet/agent.h"
#include "ctnet/handler.h"

namespace ctds
{
	extern NMCOMM_API ctnet::Agent dsAgent;

	typedef ctnet::Context context;

	FORCEINLINE void connect(const FString& Addr, const TFunction<void(bool)>& PostFunc)
	{
		dsAgent.Connect(Addr, PostFunc);
	}

	FORCEINLINE void disconnect()
	{
		dsAgent.Disconnect();
	}

	FORCEINLINE bool isconnected()
	{
		return dsAgent.IsConnected();
	}

	template<typename T> FORCEINLINE T& handler()
	{
		return dsAgent.Handler<T>();
	}
}
