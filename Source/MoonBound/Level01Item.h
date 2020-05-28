// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Subtitles.h"
#include "Engine/TargetPoint.h"
#include "Level01Item.generated.h"

UCLASS()
class MOONBOUND_API ALevel01Item : public AActor, public IInteractable
{
	GENERATED_BODY()

	UPROPERTY()
		AActor *PackPoint;
	
public:	
	// Sets default values for this actor's properties
	ALevel01Item();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA Item")
		UStaticMeshComponent *Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA Item")
		TArray<struct FSubtitles> Subtitles;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Interact_Implementation() override;
	TArray<struct FSubtitles> GetSubtitles() { return Subtitles; }
	UStaticMesh *GetMesh() { return Mesh->GetStaticMesh(); }

private:

	void SetOutline_Implementation(bool status) override;
	void EnablePhysics();

};
