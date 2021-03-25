// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class UP902463_CT6COPRE_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
		class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* CoinMesh;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
		class USphereComponent* SphereCollider;

	UFUNCTION()
		void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
