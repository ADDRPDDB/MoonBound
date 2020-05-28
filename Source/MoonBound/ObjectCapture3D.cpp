// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectCapture3D.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneCaptureComponent2D.h"

// Sets default values
AObjectCapture3D::AObjectCapture3D()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	CapturedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Captured Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Cam = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Camera"));

	RootComponent = RootComp;
	SpringArm->SetupAttachment(RootComp);
	Cam->SetupAttachment(SpringArm);
	CapturedMesh->SetupAttachment(RootComp);

}

// Called when the game starts or when spawned
void AObjectCapture3D::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjectCapture3D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CapturedMesh->AddWorldRotation(FRotator(0, RotatingSpeed*DeltaTime, 0));
}

void AObjectCapture3D::SetMesh(UStaticMesh * NewMesh)
{
	if (!CapturedMesh || !NewMesh)
		return;

	CapturedMesh->SetStaticMesh(NewMesh);
}

