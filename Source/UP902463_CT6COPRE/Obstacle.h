// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class UP902463_CT6COPRE_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Componenets")
		class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Componenets")
		class UStaticMeshComponent* StaticMesh;

	UFUNCTION()
		void OnObstacleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	// Sets default values for this actor's properties
	AObstacle();


};
