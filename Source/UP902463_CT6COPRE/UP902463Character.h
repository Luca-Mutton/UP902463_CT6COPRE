// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UP902463Character.generated.h"

UCLASS()
class UP902463_CT6COPRE_API AUP902463Character : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

	UPROPERTY(VisibleInstanceOnly)
		class AUP902463_CT6COPREGameMode* CT6COPREGameMode;


public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
		int32 CurrentLane = 1; 

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
		int32 NextLane = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MoveDownImpulse = -1000.f;


	UFUNCTION(BlueprintImplementableEvent, Category = "Lane")
		void ChangeLane();


	UFUNCTION(BlueprintCallable, Category = "Lane")
		void ChangeLaneUpdate(float Value);

	UFUNCTION(BlueprintCallable, Category = "Lane")
		void ChangeLaneFinished();

	UFUNCTION(BlueprintCallable)
		void Death();

	// Sets default values for this character's properties
	AUP902463Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnDeath();

	UFUNCTION()
		void MoveLeft();

	UFUNCTION()
		void MoveRight();

	UFUNCTION()
		void MoveDown();

	UPROPERTY()
		FTimerHandle RestartTimerHandle;

	UPROPERTY()
		bool bIsDead = false;

public:	

	UFUNCTION()
		void AddCoin();

	UFUNCTION()
		void UpdateDistance();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
