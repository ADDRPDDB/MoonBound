// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectCapture3D.generated.h"

UCLASS()
class MOONBOUND_API AObjectCapture3D : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Render", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent *CapturedMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Render", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent *SpringArm;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Render", meta = (AllowPrivateAccess = "true"))
		class USceneCaptureComponent2D *Cam;

	USceneComponent *RootComp;
	
public:	
	// Sets default values for this actor's properties
	AObjectCapture3D();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Render")
		float RotatingSpeed = 10.f;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetMesh(UStaticMesh *NewMesh);

};
