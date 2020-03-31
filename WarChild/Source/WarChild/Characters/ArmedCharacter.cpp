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