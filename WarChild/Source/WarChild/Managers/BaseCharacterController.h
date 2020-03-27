// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "BaseCharacterController.generated.h"


	DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FBeginOverlapSignature, UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor,
	UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex, bool, bFromSweep,
		const FHitResult, &SweepResult);


/**
 * 
 */
UCLASS()
class WARCHILD_API ABaseCharacterController : public AController
{
	GENERATED_BODY()

private:
	float movSpeed;
	float sensitivity;
	float pitch;
	float maxPitch;
	float yaw;
	float jumpSpeed;
	bool jumping;



	UPROPERTY()
	FBeginOverlapSignature BegunOverlap;


public:
	ABaseCharacterController(const FObjectInitializer& ObjectInitializer);
	~ABaseCharacterController();

	// Called every frame
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult &SweepResult);

};
