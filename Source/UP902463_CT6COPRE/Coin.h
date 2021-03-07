// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

UCLASS()
class UP902463_CT6COPRE_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
		class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* CoinMesh;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
		class USphereComponent* SphereCollider;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
		class URotatingMovementComponent* RotatingMovement;


	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION()
		void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
