// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

ABaseCharacter::~ABaseCharacter()
{
	delete stats;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	active = false;
	SetStats();
}

void ABaseCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABaseCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABaseCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value * stats->GetMovSpeed());
	}
}

void ABaseCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value * stats->GetMovSpeed());
	}
}

void ABaseCharacter::Damaged(float amount)
{
	if (stats->ReduceCurrentHP(amount) <= 0)
	{
		Die();
	}
}

void ABaseCharacter::SetSpawnPoint(FVector position)
{
	spawnPoint = position;
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorRotation(FRotator(FMath::ClampAngle(GetActorRotation().Pitch, -30.0f, 30.0f), GetActorRotation().Yaw, GetActorRotation().Roll));

	if (GetActorLocation().Z < -2000.0f)
	{
		Die();
	}
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

CharacterStats* ABaseCharacter::GetStats()
{
	return stats;
}

float ABaseCharacter::GetHealthFraction()
{
	return stats->GetCurrentHP() / stats->GetMaxHealth();
}