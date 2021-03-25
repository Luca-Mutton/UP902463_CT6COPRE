// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UP902463_CT6COPREGameMode.generated.h"

class AFloorTile;
class UUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCoinsCountChanged, int32, Score);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyCountChanged, int32, EnemyScore);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDistanceChanged, int32, DistanceCounter);

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

	UFUNCTION(BlueprintCallable)
		void AddEnemy();

	UFUNCTION(BlueprintCallable)
		void UpdateDistance();


	UPROPERTY(VisibleAnywhere)
		int32 TotalEnemy = 0;

	UPROPERTY(VisibleAnywhere)
		int32 TotalCoins = 0;

	UPROPERTY(VisibleAnywhere)
		float Distance = 0;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
		FOnCoinsCountChanged OnCoinsCountChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
		FOnEnemyCountChanged OnEnemyCountChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
		FOnDistanceChanged OnDistanceChanged;

protected:
	virtual void BeginPlay() override;

	AUP902463_CT6COPREGameMode();

//private:
//	float CurrentDistance;
//
//public:
//	 Called every frame
//	virtual void Tick(float DeltaTime) override;
};



