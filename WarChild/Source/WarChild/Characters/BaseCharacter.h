// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Stats/CharacterStats.h"
#include "Weapon/Weapon.h"
#include "BaseCharacter.generated.h"

UCLASS(abstract)
class WARCHILD_API ABaseCharacter : public ACharacter
{
private:

	GENERATED_BODY()

	FVector spawnPoint;
	AWeapon* equippedWeapon;

protected:

	bool active;
	CharacterStats* stats;

private:

	void Pause();
	void UnPause();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this character's properties
	ABaseCharacter();

	void Spawn();
	void PullTrigger();
	void TakeDamage(float amount);
	virtual void Die() PURE_VIRTUAL(ABaseCharacter::Die, ;);

	void SetSpawnPoint(FVector);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetEquippedWeapon(AWeapon* weapon);
	AWeapon* GetEquippedWeapon();

	virtual void SetStats() PURE_VIRTUAL(ABaseCharacter::SetStats, ;);
	CharacterStats* GetStats();
	float GetHealthFraction();
};
