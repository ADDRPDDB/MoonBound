// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Subtitles.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FSubtitles
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DisplayTime;


};