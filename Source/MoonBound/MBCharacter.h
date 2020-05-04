// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MBCharacter.generated.h"

UCLASS()
class MOONBOUND_API AMBCharacter : public ACharacter
{
	GENERATED_BODY()

	bool bCanMove = true;
	bool bCanCameraRotate = true;
	bool bCanInteract = true;

	UPROPERTY()
		AActor *LastSeenActor;
	UPROPERTY()
		AActor *LastSeenActor_Prev;

public:
	// Sets default values for this character's properties
	AMBCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Settings")
		float MoveSpeed = 200.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Settings")
		float RaytraceRange = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character Settings")
		class UCameraComponent *Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void Interact();

	void MoveForward(float value);
	void MoveRight(float value);
	void MouseX(float value);
	void MouseY(float value);

	void Raytrace();

	
	
};
