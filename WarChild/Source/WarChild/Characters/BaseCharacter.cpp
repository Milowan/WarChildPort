// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	active = false;
}

void ABaseCharacter::Spawn()
{
	FHitResult output;
	SetActorLocation(spawnPoint, false, &output, ETeleportType::TeleportPhysics);
	active = true;
}

void ABaseCharacter::SetSpawnPoint(FVector position)
{
	spawnPoint = position;
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::Pause()
{
	SetActorTickEnabled(false);
}

void ABaseCharacter::UnPause()
{
	if (active)
		SetActorTickEnabled(true);
}