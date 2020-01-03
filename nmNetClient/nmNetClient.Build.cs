using UnrealBuildTool;

public class NmNetClient : ModuleRules
{
    public NmNetClient(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange
            (
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "Sockets",
                "Networking"
            }
        );
    }
}
