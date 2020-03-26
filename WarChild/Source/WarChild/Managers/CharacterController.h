// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/PlayerCharacter.h"

/**
 * 
 */
UCLASS()
[event_source(native)]
class WARCHILD_API CharacterController : public AActor
{

private:
	float movSpeed;
	float sensitivity;
	float pitch;
	float maxPitch;
	float yaw;
	float jumpSpeed;
	bool jumping;

	UCameraComponent* playerCamera;
	APlayerCharacter* player;
	

public:
	CharacterController();
	~CharacterController();

	// Called every frame
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent,	AActor* OtherActor,
							  UPrimitiveComponent* OtherComp,	int32 OtherBodyIndex, bool bFromSweep,
							  const FHitResult &SweepResult);

	__event void MyEvent(int nValue);


protected:


};
