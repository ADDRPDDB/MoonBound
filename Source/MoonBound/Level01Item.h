// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Level01Item.generated.h"

UCLASS()
class MOONBOUND_API ALevel01Item : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevel01Item();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA Item")
		UStaticMeshComponent *Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Interact_Implementation() override;

private:

	void SetOutline_Implementation(bool status) override;

};
