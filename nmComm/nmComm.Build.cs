using UnrealBuildTool;

public class NmComm : ModuleRules
{
    public NmComm(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange
            (
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "FlatBuffers", // only valid for windows platforms, and we have no consideration for other platforms now.
                "NmNetClient",
                "Sockets",
                "Http",
                "Json",
                "NmDatacache",
            }
        );
    }
}
