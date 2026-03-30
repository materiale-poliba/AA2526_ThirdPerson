// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AA2526_ThirdPerson : ModuleRules
{
	public AA2526_ThirdPerson(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"AA2526_ThirdPerson",
			"AA2526_ThirdPerson/Variant_Platforming",
			"AA2526_ThirdPerson/Variant_Platforming/Animation",
			"AA2526_ThirdPerson/Variant_Combat",
			"AA2526_ThirdPerson/Variant_Combat/AI",
			"AA2526_ThirdPerson/Variant_Combat/Animation",
			"AA2526_ThirdPerson/Variant_Combat/Gameplay",
			"AA2526_ThirdPerson/Variant_Combat/Interfaces",
			"AA2526_ThirdPerson/Variant_Combat/UI",
			"AA2526_ThirdPerson/Variant_SideScrolling",
			"AA2526_ThirdPerson/Variant_SideScrolling/AI",
			"AA2526_ThirdPerson/Variant_SideScrolling/Gameplay",
			"AA2526_ThirdPerson/Variant_SideScrolling/Interfaces",
			"AA2526_ThirdPerson/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
