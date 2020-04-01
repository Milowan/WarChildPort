// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmedCharacter.h"


void AArmedCharacter::PullTrigger()
{
	if (equippedWeapon != NULL)
	{
		equippedWeapon->Trigger();
	}
}

void AArmedCharacter::SetEquippedWeapon(AWeapon* weapon)
{
	equippedWeapon = weapon;
}

AWeapon* AArmedCharacter::GetEquippedWeapon()
{
	return equippedWeapon;
}

void AArmedCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (equippedWeapon != NULL)
	{
		equippedWeapon->Initialize();
		equippedWeapon->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, FName(TEXT("WeaponSocket")));
	}
}