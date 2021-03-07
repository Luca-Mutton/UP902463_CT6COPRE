// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UP902463_CT6COPREGameMode.generated.h"

class AFloorTile;
class UUserWidget;

UCLASS(minimalapi)
class AUP902463_CT6COPREGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Config")
		TSubclassOf<UUserWidget> GameHUDClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UGameHUDWidget* GameHUD;

	UPROPERTY(EditAnywhere, Category = "Config")
		TSubclassOf<AFloorTile> FloorTileClass;

	UPROPERTY(EditAnywhere, Category = "Config")
		int32 NumInitialFloorTiles = 10;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		FTransform NextSpawnPoint;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		TArray<float> LaneSwitchValue; 

	UFUNCTION(BlueprintCallable)
		void CreateInitialFloorTiles();

	UFUNCTION(BlueprintCallable)
		AFloorTile* AddFloorTile(const bool bSpawnItems);

	UFUNCTION(BlueprintCallable)
		void AddCoin();

	UPROPERTY(VisibleAnywhere)
		int32 TotalCoins = 0;

protected:
	virtual void BeginPlay() override;


	AUP902463_CT6COPREGameMode();
};



