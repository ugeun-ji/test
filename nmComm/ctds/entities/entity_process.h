#pragma once

#include "ctnet/entity.h"

namespace ctds
{
	class EntityChannel;

	class NMCOMM_API EntityProcess : public ctnet::Entity
	{
	public:
		void CommConnect(FString&& ServerAddress);
		void CommClose();

		virtual void CommOnConnected() {}
	};
}