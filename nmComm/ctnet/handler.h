#pragma once

#include "agent.h"
#include "ctmsg/msg.h"
#include "ctmsg/msg_CT.h"
#include "NetClient/nmNetClient.h"
#include "NetClient/nmNetSession.h"
#include "NetClient/nmNetPacket.h"
#include "Delegates/DelegateCombinations.h"
#include "UnrealTemplate.h"

namespace ctnet
{
	#define IMPLEMENT_HANDLER_NOTIFY(handlername)\
		TArray<ctnet::FCallback> notifyCallbacks;\
	public:\
		template<class UserClass>\
		void notify(UserClass* InObj, typename ctnet::FCallbackDelegate::TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod) {\
			notifyCallbacks.Add(ctnet::FCallback(ctnet::FCallbackDelegate::CreateUObject(InObj, InMethod)));\
		}\
		template<class UserClass>\
		void notify(UserClass* InObj, typename ctnet::FCallbackDelegate::TUObjectMethodDelegate_Const<UserClass>::FMethodPtr InMethod) {\
			notifyCallbacks.Add(ctnet::FCallback(ctnet::FCallbackDelegate::CreateUObject(InObj, InMethod)));\
		}\
		template<class UserClass>\
		void unnotify(UserClass* InObj) {\
			for (TArray<ctnet::FCallback>::TIterator It(notifyCallbacks); It; ++It) {\
				if (It->IsBoundToObject(InObj)) {\
					It->Unbind();\
					It.RemoveCurrent();\
				}\
			}\
		}\
		void dispatch_notify(const MessageType* msg) {\
			ctnet::Context Ctx(GetRecvPacketType(), msg);\
			for (TArray<ctnet::FCallback>::TIterator It(notifyCallbacks); It; ++It) {\
				if (It->IsBound()) {\
					It->Execute(&Ctx);\
				}\
			}\
		}

	#define IMPLEMENT_HANDLER_RESPONSE(handlername, delegatename)\
	public:\
		template<class UserClass>\
		handlername& delegatename(UserClass* InObj, typename ctnet::FCallbackDelegate::TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod) {\
			OwnerAgent->register_callback_##delegatename(GetSendPacketType(), ctnet::FCallback(ctnet::FCallbackDelegate::CreateUObject(InObj, InMethod))); return *this;\
		}\
		template<class UserClass>\
		handlername& delegatename(UserClass* InObj, typename ctnet::FCallbackDelegate::TUObjectMethodDelegate_Const<UserClass>::FMethodPtr InMethod) {\
			OwnerAgent->register_callback_##delegatename(GetSendPacketType(), ctnet::FCallback(ctnet::FCallbackDelegate::CreateUObject(InObj, InMethod))); return *this;\
		}\
		handlername& delegatename(ctnet::FCallbackDelegate const& InDelegate) {\
			OwnerAgent->register_callback_##delegatename(GetSendPacketType(), ctnet::FCallback(InDelegate)); return *this;\
		}\
		handlername& delegatename(TFunction<void(ctnet::Context*)>&& Callback) {\
			OwnerAgent->register_callback_##delegatename(GetSendPacketType(), ctnet::FCallback(MoveTemp(Callback))); return *this;\
		}

	#define IMPLEMENT_HANDLER_TX(handlername,tx)\
		IMPLEMENT_HANDLER_RESPONSE(handlername, fail)\
	private:\
		virtual uint16 GetSendPacketType() const final { return tx; }\
	public:\
		template<typename ...Args> void send(Args&&... args) {\
			if (IsBound()) {\
				SendPacketVerified<RequestType>(tx, [&](PacketBuilder& builder)->flatbuffers::Offset<RequestType> {\
					return OnMarshal(builder, Forward<Args>(args)...);\
				});\
			}\
		}

	#define IMPLEMENT_HANDLER_RX(handlername,rx)\
		IMPLEMENT_HANDLER_NOTIFY(handlername)\
	private:\
		uint16 GetRecvPacketType() const { return rx; }\
		void PostReceive(const MessageType* msg) { dispatch_notify(msg); }

	#define IMPLEMENT_HANDLER_DUPLEX(handlername,tx,rx)\
		IMPLEMENT_HANDLER_RESPONSE(handlername, success)\
		IMPLEMENT_HANDLER_RESPONSE(handlername, fail)\
	private:\
		uint16 GetSendPacketType() const { return tx; }\
		uint16 GetRecvPacketType() const { return rx; }\
		void PostReceive(const MessageType* msg) { OwnerAgent->dispatch_success(GetSendPacketType(), msg); }\
	public:\
		template<typename ...Args> void send(Args&&... args) {\
			if (IsBound()) {\
				SendPacketVerified<RequestType>(tx, [&](PacketBuilder& builder)->flatbuffers::Offset<RequestType> {\
					return OnMarshal(builder, Forward<Args>(args)...);\
				});\
			}\
		}

	#define IMPLEMENT_HANDLER_ERROR(handlername,rx) IMPLEMENT_HANDLER_RX(handlername,rx)

	class IHandler
	{
	public:
		virtual ~IHandler() {}
	};

	template<typename RT, typename MT, typename ET=Packet::Exception::ErrorCode>
	class Handler : public IHandler
	{
	protected:
		typedef RT RequestType;
		typedef MT MessageType;
		typedef ET ErrorType;
		typedef Client::Internal::Null NullType;

	public:
		virtual ~Handler() {}

		void Bind(Agent* InAgent)
		{
			OwnerAgent = InAgent;
			Bind<RT, MT>();
		}

	private:
		template <typename RT, typename MT> typename TEnableIf<TIsSame<RT, NullType>::Value && TIsSame<MT, NullType>::Value>::Type Bind() {}
		template <typename RT, typename MT> typename TEnableIf<TIsSame<RT, NullType>::Value && !TIsSame<MT, NullType>::Value>::Type Bind() { BindRecvContext(); }
		template <typename RT, typename MT> typename TEnableIf<!TIsSame<RT, NullType>::Value && TIsSame<MT, NullType>::Value>::Type Bind() {}
		template <typename RT, typename MT> typename TEnableIf<!TIsSame<RT, NullType>::Value && !TIsSame<MT, NullType>::Value>::Type Bind() { BindRecvContext(); }

		void BindRecvContext()
		{
			OwnerAgent->BindReceivePacket(GetRecvPacketType(), FnmNetCallback::FDelegate::CreateLambda([this](const FnmNetPacketPtr& Packet) {
				ReceivePacketVerified<MessageType>(Packet);
			}));
			/*
			OwnerAgent->Session()->AddHandler(GetRecvPacketType(), FnmNetCallback::FDelegate::CreateLambda([&](const FnmNetPacketPtr& Packet)
			{
				ReceivePacketVerified<MessageType>(Packet);
			}));
			*/
		}		

	protected:
		Agent* OwnerAgent = nullptr;
		virtual void OnMessage(const MessageType* msg) {}
		virtual void PostReceive(const MessageType* msg) {}
		virtual uint16 GetSendPacketType() const { return 0; }
		virtual uint16 GetRecvPacketType() const { return 0; }
		bool IsBound() const { return OwnerAgent && OwnerAgent->Client().IsValid() && OwnerAgent->Client()->IsConnected(); }

		typedef flatbuffers::FlatBufferBuilder PacketBuilder;
		typedef flatbuffers::Offset<RequestType> PacketOffset;
		typedef flatbuffers::Verifier PacketVerifier;		

		template<typename T>
		void SendPacketVerified(const USHORT PacketType, TFunctionRef<flatbuffers::Offset<T>(PacketBuilder&)> Body)
		{
			PacketBuilder builder(1024Ui64); // @nmTODO - requires some pooling or custom allocator??
			builder.Finish<T>(Body(builder));

			PacketVerifier verifier(builder.GetBufferPointer(), builder.GetSize());
			if (verifier.VerifyBuffer<T>(nullptr))
			{
				OwnerAgent->Client()->SendPacket(PacketType, builder.GetBufferPointer(), builder.GetSize());
			}
			else
			{
				UE_LOG(LogComm, Error, TEXT("[TX] verification failed: packet=%d size=%d"), PacketType, builder.GetSize());
			}
		}

		template<typename T>
		void ReceivePacketVerified(const FnmNetPacketPtr& Packet)
		{
			flatbuffers::Verifier verifier(Packet->GetPayloadData(), Packet->GetPayloadSize());
			if (verifier.VerifyBuffer<T>(nullptr))
			{
				const T* msg = flatbuffers::GetRoot<T>(Packet->GetPayloadData());
				OnMessage(msg);
				PostReceive(msg);
			}
			else
			{
				UE_LOG(LogComm, Error, TEXT("[RX] verification failed: packet=%d size=%d"), GetRecvPacketType(), Packet->GetPayloadSize());
			}
		}
	};
}