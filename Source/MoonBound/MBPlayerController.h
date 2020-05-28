// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InspectWidget.h"
#include "MBPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOONBOUND_API AMBPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY()
		class UInspectWidget *InspectWidgetRef;

	bool bInspectWidgetOpened = false;
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UInspectWidget> InspectWidgetBP;

	virtual void OnPossess(APawn* InPawn) override;

	void InspectItem(TArray<struct FSubtitles> subs, UStaticMesh *nmesh);
	void CloseWidgets();
};
