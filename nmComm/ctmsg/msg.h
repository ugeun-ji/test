#pragma once

namespace ctmsg
{
#define constexpr static
#define XUSHORT USHORT
#include "Build/Generated/messages.h"
#undef constexpr
#undef XUSHORT
}
using namespace ctmsg;

#include "msg_CT.h"
#include "msg_LOGIN.h"
#include "msg_COMMON.h"