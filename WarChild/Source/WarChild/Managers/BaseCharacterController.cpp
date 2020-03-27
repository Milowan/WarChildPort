// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacterController.h"


ABaseCharacterController::ABaseCharacterController(const FObjectInitializer & ObjectInitializer)	

{
	//ABaseCharacterController::ABaseCharacterController(const FObjectInitializer& ObjectInitializer)
	//: Super(ObjectInitializer)
}

ABaseCharacterController::~ABaseCharacterController()
{
}

void ABaseCharacterController::BeginPlay()
{
}

void ABaseCharacterController::Tick(float DeltaTime)
{
}

void ABaseCharacterController::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}
