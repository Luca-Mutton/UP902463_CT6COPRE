// Copyright Epic Games, Inc. All Rights Reserved.

#include "UP902463_CT6COPREGameMode.h"
#include "UP902463_CT6COPRECharacter.h"
#include "UObject/ConstructorHelpers.h"

AUP902463_CT6COPREGameMode::AUP902463_CT6COPREGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
