// Fill out your copyright notice in the Description page of Project Settings.


#include "MBPlayerController.h"
#include "ObjectCapture3D.h"
#include "Kismet/GameplayStatics.h"

void AMBPlayerController::OnPossess(APawn * InPawn)
{
	Super::OnPossess(InPawn);

	if (InspectWidgetBP)
	{
		InspectWidgetRef = CreateWidget<UInspectWidget>(this, InspectWidgetBP);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("InspecWidgetBP is nullptr"));
}

void AMBPlayerController::InspectItem(TArray<struct FSubtitles> subs, UStaticMesh * nmesh)
{
	if (!InspectWidgetRef || !nmesh)
		return;

	InspectWidgetRef->UpdateSubtitles(subs);
	AObjectCapture3D *OC3D = nullptr;
	AActor *temp = UGameplayStatics::GetActorOfClass(GetWorld(), AObjectCapture3D::StaticClass());
	if (temp)
		OC3D = Cast<AObjectCapture3D>(temp);
	if (OC3D)
	{
		OC3D->SetMesh(nmesh);
	}

	InspectWidgetRef->AddToViewport();

	bInspectWidgetOpened = true;
	InspectWidgetRef->Open();
}

void AMBPlayerController::CloseWidgets()
{
	if (bInspectWidgetOpened)
	{
		InspectWidgetRef->RemoveFromViewport();
		bInspectWidgetOpened = false;
		InspectWidgetRef->Close();
	}
}
