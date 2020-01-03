#include "ctds/entities/entity_player.h"
#include "ctds/ctds.h"
#include "Datacache/nmDatacacheUtils.h"

namespace ctds
{
	using namespace Packet::Character;

	class UpdateCheckpoint : public ctnet::Handler<DSUpdateCheckpoint, Client::Internal::Null>
	{
		IMPLEMENT_HANDLER_TX(UpdateCheckpoint, D2C_UPDATE_CHECKPOINT)
		PacketOffset OnMarshal(PacketBuilder& builder, int32 charsid, int32 checkpoint)
		{
			UE_LOG(LogComm, Verbose, TEXT("DSUpdateCheckpoint charsid=%d checkpoint=%d"), charsid, checkpoint);
			return CreateDSUpdateCheckpoint(builder, charsid, checkpoint);
		}
	};

	void EntityPlayer::SaveCheckpoint(int32 checkpoint)
	{
		if (FSqliteReader(TEXT("SELECT * FROM player WHERE charsn=%d AND checkpoint!=%d"), CommGetEntityID(), checkpoint).Exists())
		{
			ctds::handler<UpdateCheckpoint>().send(CommGetEntityID(), checkpoint);
			FSqliteSql().Sql(TEXT("UPDATE player SET checkpoint=%d WHERE charsn=%d"), checkpoint, CommGetEntityID());
		}
	}
}

namespace ctnet
{
	TMap<int64, ctds::EntityPlayer*> EntityCollection<ctds::EntityPlayer>::ActiveEntities;
	TMap<FString, ctds::EntityPlayer*> EntityCollection<ctds::EntityPlayer>::PendingEntities;
}