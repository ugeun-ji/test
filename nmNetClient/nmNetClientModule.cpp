#include "nmNetClientModule.h"

class FnmNetClientModule : public InmNetClientModule
{
	virtual void StartupModule() override
	{

	}
	virtual void ShutdownModule() override
	{

	}
};

IMPLEMENT_MODULE(FnmNetClientModule, NmNetClient);