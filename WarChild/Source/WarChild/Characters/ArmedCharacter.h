// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Weapon/Weapon.h"
#include "ArmedCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AArmedCharacter : public ABaseCharacter
{
private:

	GENERATED_BODY()

protected:

	AWeapon* equippedWeapon;

public:

	AArmedCharacter(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void SetEquippedWeapon(AWeapon* weapon);
	UFUNCTION(BlueprintCallable)
	AWeapon* GetEquippedWeapon();
	void PullTrigger();

protected:

	virtual void BeginPlay() override;
	
};
