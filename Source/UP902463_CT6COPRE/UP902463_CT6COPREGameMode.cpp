// Copyright Epic Games, Inc. All Rights Reserved.

#include "UP902463_CT6COPREGameMode.h"
#include "UP902463_CT6COPRECharacter.h"
#include "FloorTile.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameHUDWidget.h"

void AUP902463_CT6COPREGameMode::CreateInitialFloorTiles()
{

	AFloorTile* Tile = AddFloorTile(false);

	if (Tile)
	{
		LaneSwitchValue.Add(Tile->LeftLane->GetComponentLocation().Y);
		LaneSwitchValue.Add(Tile->CentreLane->GetComponentLocation().Y);
		LaneSwitchValue.Add(Tile->RightLane->GetComponentLocation().Y);
	}


	AddFloorTile(false);
	AddFloorTile(false);

	for (int i = 0; i < NumInitialFloorTiles; i++)
	{
		AddFloorTile(true);
	}
}

AFloorTile* AUP902463_CT6COPREGameMode::AddFloorTile(const bool bSpawnItems)
{
	UWorld* World = GetWorld();

	if (World)
	{
		AFloorTile* Tile = World->SpawnActor<AFloorTile>(FloorTileClass, NextSpawnPoint);

		if (Tile)
		{
			if (bSpawnItems)
			{
				Tile->SpawnItems();
			}
			NextSpawnPoint = Tile->GetAttachTransform();
		}

		return Tile;
	}

	return nullptr;
}

void AUP902463_CT6COPREGameMode::AddCoin()
{
	TotalCoins += 1;

	UE_LOG(LogTemp, Warning, TEXT("TOTAL COINS: %d"), TotalCoins);
}

void AUP902463_CT6COPREGameMode::BeginPlay()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	GameHUD = Cast<UGameHUDWidget>(CreateWidget(GetWorld(), GameHUDClass));
	check(GameHUD);

	GameHUD->AddToViewport();

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
