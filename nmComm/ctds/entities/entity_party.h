#pragma once

#include "ctnet/entity.h"

namespace ctds
{
	class EntityPlayer;

	class NMCOMM_API EntityParty : public ctnet::Entity
	{
		CTNET_ENTITY_MEMBER(DSID, int32)
		CTNET_ENTITY_MEMBER(ChannelID, int32)

	public:
		void CommEnsureLocalMember(EntityPlayer* Player);
		void CommEnsureRemoteMember(int64 CharID, const FString& CharName);
		void CommBeginUpdateMembers();
		void CommEndUpdateMembers();

		void CommEnterParty(EntityPlayer* Player);
		void CommLeaveParty(EntityPlayer* Player);
	};
}