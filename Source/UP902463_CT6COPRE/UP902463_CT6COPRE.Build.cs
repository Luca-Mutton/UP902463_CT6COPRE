// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UP902463_CT6COPRE : ModuleRules
{
	public UP902463_CT6COPRE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
