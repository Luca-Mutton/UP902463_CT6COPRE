// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "FloorTile.generated.h"


class USceneComponent;
class UStaticMeshComponent;
class UBoxComponent;
class AObstacle;
class ACoin;

UCLASS()
class UP902463_CT6COPRE_API AFloorTile : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
		TSubclassOf<AObstacle> SmallObstacleClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
		TSubclassOf<AObstacle> BigObstacleClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
		TSubclassOf<ACoin> CoinClass;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components")
		USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components")
		UStaticMeshComponent* FloorMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components")
		UArrowComponent* AttachPoint;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components")
		UArrowComponent* CentreLane;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components")
		UArrowComponent* LeftLane;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components")
		UArrowComponent* RightLane;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components")
		UBoxComponent* FloorTriggerBox;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Config")
		float SpawnPercent1 = 0.1f;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Config")
		float SpawnPercent2 = 0.3f;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Config")
		float SpawnPercent3 = 0.5f;

	UFUNCTION(BlueprintCallable)
		void SpawnItems();

	// Sets default values for this actor's properties
	AFloorTile();

	FORCEINLINE const FTransform& GetAttachTransform() const
	{
		return AttachPoint->GetComponentTransform();
	}

protected:
	UPROPERTY(VisibleInstanceOnly)
		class AUP902463_CT6COPREGameMode* CT6COPREGameMode;

	UPROPERTY()
		FTimerHandle DestroyHandle;

	UFUNCTION()
		void OnTriggerBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void DestroyFloorTile();

	UFUNCTION()
		void SpawnLaneItem(UArrowComponent* Lane, int32& NumBigs);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
