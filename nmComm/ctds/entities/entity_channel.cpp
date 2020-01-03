#include "ctds/entities/entity_channel.h"
#include "ctds/ctds.h"

namespace ctnet
{
	TMap<int64, ctds::EntityChannel*> EntityCollection<ctds::EntityChannel>::ActiveEntities;
	TMap<FString, ctds::EntityChannel*> EntityCollection<ctds::EntityChannel>::PendingEntities;
}