// Fill out your copyright notice in the Description page of Project Settings.

#include "MBCharacter.h"
#include "Camera/CameraComponent.h"


// Sets default values
AMBCharacter::AMBCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector(0, 0, 80.f));

}

// Called when the game starts or when spawned
void AMBCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMBCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMBCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AMBCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AMBCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseX", this, &AMBCharacter::MouseX);
	PlayerInputComponent->BindAxis("MouseY", this, &AMBCharacter::MouseY);

}

void AMBCharacter::MoveForward(float value)
{
	if (!bCanMove)
		return;

	AddMovementInput(GetActorForwardVector(), value*MoveSpeed);
}

void AMBCharacter::MoveRight(float value)
{
	if (!bCanMove)
		return;

	AddMovementInput(GetActorRightVector(), value*MoveSpeed);
}

void AMBCharacter::MouseX(float value)
{
	if (!bCanCameraRotate)
		return;

	ACharacter::AddControllerYawInput(value);
}

void AMBCharacter::MouseY(float value)
{
	if (!bCanCameraRotate)
		return;

	ACharacter::AddControllerPitchInput(value);
}

void AMBCharacter::Raytrace()
{
	if (!bCanInteract)
		return;
}

