// Copyright Epic Games, Inc. All Rights Reserved.

#include "UP902463_CT6COPREGameMode.h"
#include "UP902463_CT6COPRECharacter.h"
#include "UObject/ConstructorHelpers.h"

void AUP902463_CT6COPREGameMode::CreateInitialFloorTiles()
{
	for (int i = 0; i < NumInitialFloorTiles; i++)
	{
		AddFloorTile();
	}
}

void AUP902463_CT6COPREGameMode::AddFloorTile()
{
	UWorld* World = GetWorld();

	if (World)
	{
		AFloorTile* Tile = World->SpawnActor<AFloorTile>(FloorTileClass, NextSpawnPoint);

		if (Tile)
		{
			NextSpawnPoint = Tile->GetAttachTransform();
		}
	}
}

void AUP902463_CT6COPREGameMode::BeginPlay()
{
	CreateInitialFloorTiles();
}

AUP902463_CT6COPREGameMode::AUP902463_CT6COPREGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
