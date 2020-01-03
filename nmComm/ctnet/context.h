#pragma once

#include "ctmsg/msg.h"
#include "ctmsg/msg_COMMON.h"

namespace ctnet
{
	class Context
	{
	public:
		USHORT msgtype = 0;
		const void* msgptr = nullptr;
		const Packet::Exception::ErrorCode* error = nullptr;

		Context() {}
		Context(USHORT type, const void* msg) : msgtype(type), msgptr(msg) {}
		Context(const Packet::Exception::ErrorCode* err) : error(err) {}

		template<typename T> const T* Msgref() { return (const T*)(msgptr); }
		bool IsOK() const { return error && error->code() == Packet::Exception::Code_OK; }
		bool IsError(const int16 code) const { return error && error->code() == code; }
	};

	DECLARE_DELEGATE_OneParam(FCallbackDelegate, Context*);

	struct FCallback
	{
		FCallbackDelegate FuncDelegate;
		TFunction<void(ctnet::Context*)> FuncCallback;

		FCallback() {};
		FCallback(FCallbackDelegate const& D) : FuncDelegate(D) {};
		FCallback(TFunction<void(ctnet::Context*)>&& Callback) : FuncCallback(MoveTemp(Callback)) {}

		inline void Execute(ctnet::Context* Ctx)
		{
			if (FuncDelegate.IsBound())
			{
#if STATS
				TStatId StatId = TStatId();
				UObject* Object = FuncDelegate.GetUObject();
				if (Object)
				{
					StatId = Object->GetStatID();
				}
				FScopeCycleCounter Context(StatId);
#endif
				FuncDelegate.Execute(Ctx);
			}
			else if (FuncCallback)
			{
				FuncCallback(Ctx);
			}
		}
		inline bool IsBound() const
		{
			return (FuncDelegate.IsBound() || FuncCallback);
		}
		inline bool IsBoundToObject(void const* Object) const
		{
			if (FuncDelegate.IsBound())
			{
				return FuncDelegate.IsBoundToObject(Object);
			}

			return false;
		}
		inline void Unbind()
		{
			FuncDelegate.Unbind();
			FuncCallback = nullptr;
		}
	};
}