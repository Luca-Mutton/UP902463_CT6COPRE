// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDWidget.h"
#include "Components/TextBlock.h"

void UGameHUDWidget::InitailizeHUD(AUP902463_CT6COPREGameMode* GameMode)
{
	if (GameMode)
	{
		Score->SetText(FText::AsNumber(0));
		DistanceCounter->SetText(FText::AsNumber(0));

		GameMode->OnCoinsCountChanged.AddDynamic(this, &UGameHUDWidget::SetCoinsCount);

		GameMode->OnDistanceChanged.AddDynamic(this, &UGameHUDWidget::SetDistance);
	}
}

void UGameHUDWidget::SetCoinsCount(const int32 Count)
{
	Score->SetText(FText::AsNumber(Count));
}

void UGameHUDWidget::UpdateDistance(float Distance)
{
	/*if (DistanceCounter == nullptr) return;

	float rounded = roundf(Distance);

	FNumberFormattingOptions NumberFormat;
	NumberFormat.MinimumFractionalDigits = 0;
	NumberFormat.MaximumFractionalDigits = 10;

	FText NewDistance = FText::AsNumber(rounded, &NumberFormat);

	DistanceCounter->SetText(NewDistance);*/
}
