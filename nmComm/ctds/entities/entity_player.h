#pragma once

#include "ctnet/entity.h"
#include "ctmsg/msg_CT.h"
#include "Serialization/Archive.h"

namespace ctds
{
	class NMCOMM_API EntityPlayer : public ctnet::Entity
	{
	public:
		void SaveCheckpoint(int32 Checkpoint);

		virtual ~EntityPlayer() {}
		virtual void CommEventMatchSuccess(int32 dsid, int32 chanid, uint64 hash) const {}
		virtual void CommEventMatchCleanup(int32 dsid, int32 chanid, uint64 hash) const {}
	};
}