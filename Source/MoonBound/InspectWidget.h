// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Subtitles.h"
#include "InspectWidget.generated.h"

/**
 * 
 */
UCLASS()
class MOONBOUND_API UInspectWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TArray<struct FSubtitles> Subtitles;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		FString CurrentText;
	UPROPERTY()
		int32 CurrSub;
	UPROPERTY()
		FTimerHandle SubtitlesTimer;


	void ChangeSubtitles();
public:
	void UpdateSubtitles(TArray<struct FSubtitles> subs);
	void Open();
	void Close();
};
