#pragma once

#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "CoreDelegates.h"
#include "Tickable.h"
#include "NetClient/nmNetClient.h"
#include "NetClient/nmNetSession.h"
#include "NetClient/nmNetPacket.h"
#include "context.h"

NMCOMM_API DECLARE_LOG_CATEGORY_EXTERN(LogComm, Log, All);

namespace ctnet
{
	class FResponseCallbackContext
	{
		TMap<int16, TTuple<FCallback, FCallback>> CallbackMap;

	public:
		void register_callback_success(const int16 Type, FCallback Callback)
		{
			if (Callback.IsBound())
			{
				TTuple<FCallback, FCallback>& CallbackTuple = CallbackMap.FindOrAdd(Type);
				FCallback& Cb = CallbackTuple.Get<0>();
				Cb = Callback;
			}
		}
		void register_callback_fail(const int16 Type, FCallback Callback)
		{
			if (Callback.IsBound())
			{
				TTuple<FCallback, FCallback>& CallbackTuple = CallbackMap.FindOrAdd(Type);
				FCallback& Cb = CallbackTuple.Get<1>();
				Cb = Callback;
			}
		}
		void dispatch_success(const int16 Type, const void* Message)
		{
			TTuple<FCallback, FCallback>& CallbackTuple = CallbackMap.FindOrAdd(Type);
			FCallback& Cb = CallbackTuple.Get<0>();
			if (Cb.IsBound())
			{
				Context Ctx(Type, Message);
				Cb.Execute(&Ctx);
				Cb.Unbind();
				CallbackMap.Remove(Type);
			}
		}
		void dispatch_fail(const int16 Type, const Packet::Exception::ErrorCode* Error)
		{
			TTuple<FCallback, FCallback>& CallbackTuple = CallbackMap.FindOrAdd(Type);
			FCallback& Cb = CallbackTuple.Get<1>();
			if (Cb.IsBound())
			{
				Context Ctx(Error);
				Cb.Execute(&Ctx);
				Cb.Unbind();
				CallbackMap.Remove(Type);
			}
		}
	};

	class Agent : public FTickableGameObject, public FResponseCallbackContext
	{
	public:
		FnmNetClientPtr& Client() { return NetClient; }
		FnmNetSessionPtr& Session() { return NetSession; }
		template<typename T> T& Handler();

		virtual void OnReceive(const FnmNetPacketPtr Packet) final
		{
			const uint16 Type = Packet->GetPacketType();

			if (Type == C2D_UNEXPECTED_ERROR)
			{				
				flatbuffers::Verifier verifier(Packet->GetPayloadData(), Packet->GetPayloadSize());
				if (verifier.VerifyBuffer<Packet::Exception::ErrorCode>(nullptr))
				{
					const Packet::Exception::ErrorCode* msg = flatbuffers::GetRoot<Packet::Exception::ErrorCode>(Packet->GetPayloadData());

					UE_LOG(LogComm, Verbose, TEXT("ErrorCode msg=%d code=[%d:%s] condition=%d"), msg->req(), msg->code(), UTF8_TO_TCHAR(Packet::Exception::EnumNameCode(msg->code())), msg->condition());

					if (msg->req() != 0 /*&& msg->code() != Packet::Exception::Code_OK*/)
					{
						dispatch_fail(msg->req(), msg);
					}
				}
			}

			FnmNetCallback* CbPtr = PacketBindMap.Find(Type);
			if (CbPtr)
			{
				CbPtr->Broadcast(Packet);
			}
			else
			{
				UE_LOG(LogComm, Error, TEXT("Packet %d received but not bound, add packet handler"), Type);
			}
		}

		void BindReceivePacket(uint64 RecvPacketType, FnmNetCallback::FDelegate Delegate)
		{
			FnmNetCallback& Callback = PacketBindMap.FindOrAdd(RecvPacketType);
			Callback.Add(Delegate);
		}

		typedef TFunction<void(bool)> FConnectResultFunction;
		FConnectResultFunction ConnectResultFunction;

		static void HandleConnectionEstablished(FnmNetSessionPtr& NetSession, Agent* TargetAgent)
		{
			NetSession->SetPacketListener(FnmNetCallback::FDelegate::CreateLambda([TargetAgent](const FnmNetPacketPtr& Packet) {
				TargetAgent->OnReceive(Packet);
			}));

			TargetAgent->NetSession = NetSession;
			if (TargetAgent->ConnectResultFunction)
			{
				TargetAgent->ConnectResultFunction(true);
			}			
		}

		static void HandleConnectionRejected(bool, Agent* TargetAgent)
		{
			if (TargetAgent->ConnectResultFunction)
			{
				TargetAgent->ConnectResultFunction(false);
			}
		}

		Agent& Connect(const FString& IpPort, FConnectResultFunction ResultFunc)
		{
			check(!NetClient.IsValid());
			NetClient = MakeShareable(new FnmNetClient(*IpPort));
			ConnectResultFunction = ResultFunc;
			NetClient->OnSessionEstablished.AddStatic(&HandleConnectionEstablished, this);
			NetClient->OnSessionRejected.AddStatic(&HandleConnectionRejected, this);
			FCoreDelegates::OnPreExit.AddRaw(this, &Agent::OnPreExit);
			return *this;
		}

		void Disconnect()
		{
			if (NetClient.IsValid())
			{
				NetClient->Close();
				NetClient.Reset();
			}
		}

		bool IsConnected()
		{
			return NetClient.IsValid() && NetClient->IsConnected();
		}

		void OnPreExit()
		{
			Disconnect();
		}

		~Agent()
		{
			Disconnect();
		}

	private:
		FnmNetClientPtr NetClient;
		FnmNetSessionPtr NetSession;
		TMap<FString, TSharedPtr<class IHandler>> HandlerMap;
		TMap<uint64, FnmNetCallback> PacketBindMap;

		// FTickableGameObject
		virtual void Tick(float DeltaTime) final { NetClient->Tick(DeltaTime); }
		virtual TStatId GetStatId() const final { RETURN_QUICK_DECLARE_CYCLE_STAT(Agent, STATGROUP_Tickables); }
		virtual bool IsTickable() const final { return NetClient.IsValid(); }
		virtual bool IsTickableWhenPaused() const final { return true; }
		// ~FTickableGameObject
	};

	template<typename T> T& Agent::Handler()
	{
		const FString name = typeid(T).name();		
		if (HandlerMap.Contains(name))
		{
			return *StaticCastSharedPtr<T>(HandlerMap.FindChecked(name)).Get();
		}

		TSharedPtr<T> h = MakeShareable(new T());
		h->Bind(this);
		HandlerMap.Add(name, h);
		return *StaticCastSharedPtr<T>(h).Get();
	}
}