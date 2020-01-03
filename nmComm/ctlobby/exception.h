#pragma once

#include "ctnet/handler.h"

namespace ctlobby
{
	class Exception : public ctnet::Handler<Client::Internal::Null, Packet::Exception::ErrorCode>
	{
	public:
		IMPLEMENT_HANDLER_ERROR(Exception, C2D_UNEXPECTED_ERROR)
		void OnMessage(const MessageType* msg)
		{
			if (msg->req() != 0)
			{
				OwnerAgent->dispatch_fail(msg->req(), msg);
			}
		}
	};
}