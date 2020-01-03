#include "ctds/entities/entity_party.h"
#include "ctds/entities/entity_player.h"

namespace ctds
{
	void EntityParty::CommEnsureLocalMember(EntityPlayer* Player)
	{
		// @nmTODO
	}

	void EntityParty::CommEnsureRemoteMember(int64 CharID, const FString& CharName)
	{
		// @nmTODO
	}

	void EntityParty::CommBeginUpdateMembers()
	{
		// @nmTODO
		// mark all members pending update
	}

	void EntityParty::CommEndUpdateMembers()
	{
		// @nmTODO
		// remove all pending update marked members
	}

	void EntityParty::CommEnterParty(EntityPlayer* Player)
	{
		// @ctds::party
		////if (CommGetEntityActive())
		////{
		////	ctds::handler<ctds::EnterParty>().send(CommGetEntityID(), Player->CommGetEntityID());
		////}
	}

	void EntityParty::CommLeaveParty(EntityPlayer* Player)
	{
		// @ctds::party
		////if (CommGetEntityActive())
		////{
		////	ctds::handler<ctds::LeaveParty>().send(CommGetEntityID(), Player->CommGetEntityID());
		////}
	}
}

namespace ctnet
{
	TMap<int64, ctds::EntityParty*> EntityCollection<ctds::EntityParty>::ActiveEntities;
	TMap<FString, ctds::EntityParty*> EntityCollection<ctds::EntityParty>::PendingEntities;
}