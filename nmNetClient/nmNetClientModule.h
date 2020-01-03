#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class InmNetClientModule : public IModuleInterface
{
public:
	static inline InmNetClientModule& Get()
	{
		return FModuleManager::LoadModuleChecked<InmNetClientModule>("nmNetClient");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("nmNetClient");
	}
};

