// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UP902463_CT6COPREGameMode.h"
#include "GameHUDWidget.generated.h"


/**
 * 
 */
UCLASS()
class UP902463_CT6COPRE_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Score;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* DistanceCounter;

public:
	UFUNCTION(BlueprintCallable)
		void InitailizeHUD(AUP902463_CT6COPREGameMode* GameMode);

	UFUNCTION(BlueprintCallable)
		void SetCoinsCount(int32 Count);

	UFUNCTION(BlueprintCallable)
		void SetDistance(float distance);

	UFUNCTION(BlueprintCallable)
		void UpdateDistance(float Distance);
};
