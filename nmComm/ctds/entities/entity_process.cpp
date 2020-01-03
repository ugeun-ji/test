#include "ctds/entities/entity_process.h"
#include "ctds/ctds.h"

namespace ctds
{
	void EntityProcess::CommConnect(FString&& ServerAddress)
	{
		ctds::connect(ServerAddress, [this](bool bSuccess)
		{
			if (bSuccess)
			{
				CommOnConnected();
			}
			else
			{
				UE_LOG(LogComm, Error, TEXT("Couldn't connect to CT server"));
			}
		});
	}

	void EntityProcess::CommClose()
	{
	}
}

namespace ctnet
{
	TMap<int64, ctds::EntityProcess*> EntityCollection<ctds::EntityProcess>::ActiveEntities;
	TMap<FString, ctds::EntityProcess*> EntityCollection<ctds::EntityProcess>::PendingEntities;
}