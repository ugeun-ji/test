using UnrealBuildTool;
using System.IO;
using System;

public class FlatBuffers : ModuleRules
{
    public FlatBuffers(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        string FBPath = ModuleDirectory;
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            FBPath += "/x64-windows";
        }
        else if (Target.Platform == UnrealTargetPlatform.Win32)
        {
            FBPath += "/x86-windows";
        }
        else
        {
            throw new BuildException("NM doesn't support FlatBuffers for non-windows platforms");
        }

        PublicSystemIncludePaths.Add(FBPath + "/include");
        PublicLibraryPaths.Add(FBPath + "/lib");
        PublicAdditionalLibraries.Add(FBPath + "/lib/flatbuffers.lib");
    }
}
