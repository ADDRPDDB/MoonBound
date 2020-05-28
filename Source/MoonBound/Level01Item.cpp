// Fill out your copyright notice in the Description page of Project Settings.


#include "Level01Item.h"
#include "PackPoint.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


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

	PackPoint = UGameplayStatics::GetActorOfClass(GetWorld(), APackPoint::StaticClass());
	
}

// Called every frame
void ALevel01Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevel01Item::Interact_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("%s on duty"), *GetName());
	
	if (PackPoint)
	{
		SetActorLocation(PackPoint->GetActorLocation());
		FTimerHandle EnablePhysicsTimer;
		GetWorldTimerManager().SetTimer(EnablePhysicsTimer,this, &ALevel01Item::EnablePhysics, 0.5f, false);
	}
	
}

void ALevel01Item::SetOutline_Implementation(bool status)
{
	if (!Mesh)
		return;

	Mesh->SetRenderCustomDepth(status);
}

void ALevel01Item::EnablePhysics()
{
	Mesh->SetSimulatePhysics(true);
}

