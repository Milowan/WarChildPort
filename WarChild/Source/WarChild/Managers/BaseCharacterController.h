// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "BaseCharacterController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FBeginOverlapSignature1, UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex, bool, bFromSweep, const FHitResult&, SweepResult);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRamaMeleeHitSignature, class AActor*, HitActor);
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
	FBeginOverlapSignature1 BegunOverlap;

	UPROPERTY()
	FRamaMeleeHitSignature onHit;


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
