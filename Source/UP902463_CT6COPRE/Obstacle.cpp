// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "UP902463Character.h"

void AObstacle::OnObstacleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AUP902463Character* RunnerCharacter = Cast<AUP902463Character>(OtherActor);

	if (RunnerCharacter)
	{
		RunnerCharacter->Death();
	}
}

// Sets default values
AObstacle::AObstacle()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneComponent);

	StaticMesh->OnComponentHit.AddDynamic(this, &AObstacle::OnObstacleHit);
}



