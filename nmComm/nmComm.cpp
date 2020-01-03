#include "CoreMinimal.h"
#include "ModuleInterface.h"
#include "ctnet/handler.h"

class FnmCommModule : public IModuleInterface
{
	virtual void StartupModule() override
	{

	}
	virtual void ShutdownModule() override
	{
	}
};

IMPLEMENT_MODULE(FnmCommModule, NmComm);
DEFINE_LOG_CATEGORY(LogComm);
DEFINE_LOG_CATEGORY(LogCommEntity);