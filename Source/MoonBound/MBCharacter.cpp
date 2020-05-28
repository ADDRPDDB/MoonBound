// Fill out your copyright notice in the Description page of Project Settings.

#include "MBCharacter.h"
#include "Camera/CameraComponent.h"
#include "Interactable.h"
#include "Level01Item.h"
#include "MBPlayerController.h"


// Sets default values
AMBCharacter::AMBCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector(0, 0, 80.f));
	Camera->bUsePawnControlRotation = true;

	

	

}

// Called when the game starts or when spawned
void AMBCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	LastSeenActor_Prev = nullptr;
}

// Called every frame
void AMBCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Raytrace();
}

// Called to bind functionality to input
void AMBCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AMBCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AMBCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseX", this, &AMBCharacter::MouseX);
	PlayerInputComponent->BindAxis("MouseY", this, &AMBCharacter::MouseY);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMBCharacter::Interact);
	PlayerInputComponent->BindAction("Esc", IE_Pressed, this, &AMBCharacter::Esc);

}

void AMBCharacter::Interact()
{
	
	if (!bCanInteract)
		return;
	if (!LastSeenActor)
		return;

	if (Cast<ALevel01Item>(LastSeenActor))
	{
		ALevel01Item *temp = Cast<ALevel01Item>(LastSeenActor);
		AMBPlayerController *ctrl = Cast<AMBPlayerController>(GetController());

		if (ctrl)
		{
			ctrl->InspectItem(temp->GetSubtitles(), temp->GetMesh());
			bCanMove = false;
			bCanCameraRotate = false;
			bCanInteract = false;
			bAnyWidgetOpened = true;
		}
	}

	IInteractable::Execute_Interact(LastSeenActor);
}

void AMBCharacter::Esc()
{
	if (bAnyWidgetOpened)
	{
		AMBPlayerController *ctrl = Cast<AMBPlayerController>(GetController());

		if (ctrl)
		{
			ctrl->CloseWidgets();
			bAnyWidgetOpened = false;
			bCanMove = true;
			bCanCameraRotate = true;
			bCanInteract = true;
		}
	}
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

	FVector StartLocation = Camera->GetComponentLocation();
	FVector EndLocation = StartLocation + Camera->GetForwardVector()*RaytraceRange;

	FCollisionQueryParams CQP(FName("Interact"), true, this);

	FHitResult Result;

	GetWorld()->LineTraceSingleByChannel(OUT Result, StartLocation, EndLocation, ECollisionChannel::ECC_WorldDynamic, CQP);

	if (!Result.GetActor())
	{
		LastSeenActor = nullptr;
	}
	else
	{

		IInteractable *InteractableActor = Cast<IInteractable>(Result.GetActor());

		if (InteractableActor)
		{
			if (Result.GetActor() != LastSeenActor)
			{
				LastSeenActor = Result.GetActor();
				UE_LOG(LogTemp, Warning, TEXT("%s found"), *LastSeenActor->GetName());
			}
		}
		else
		{
			LastSeenActor = nullptr;
		}
	}
	if (LastSeenActor != LastSeenActor_Prev)
	{
		if (LastSeenActor_Prev)
			IInteractable::Execute_SetOutline(LastSeenActor_Prev, false);
		if(LastSeenActor)
			IInteractable::Execute_SetOutline(LastSeenActor, true);
		
		LastSeenActor_Prev = LastSeenActor;
		UE_LOG(LogTemp, Warning, TEXT("outline"));
	}
}

