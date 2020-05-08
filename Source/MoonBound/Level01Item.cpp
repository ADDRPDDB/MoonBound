// Fill out your copyright notice in the Description page of Project Settings.


#include "Level01Item.h"

// Sets default values
ALevel01Item::ALevel01Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ALevel01Item::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevel01Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevel01Item::Interact_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("%s on duty"), *GetName());
}

void ALevel01Item::SetOutline_Implementation(bool status)
{
	if (!Mesh)
		return;

	Mesh->SetRenderCustomDepth(status);
}

