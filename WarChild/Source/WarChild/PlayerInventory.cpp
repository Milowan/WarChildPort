// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInventory.h"

UPlayerInventory* UPlayerInventory::instance = NULL;

UPlayerInventory* UPlayerInventory::GetInstance()
{
	if (instance == NULL)
		instance = NewObject<UPlayerInventory>();
	return instance;
}

void UPlayerInventory::Release()
{
	instance = NULL;
}

void UPlayerInventory::SetEquippedWeapon(TSubclassOf<class AWeapon> weapon)
{
	equippedWeapon = weapon;
}

TSubclassOf<class AWeapon> UPlayerInventory::GetEquippedWeapon()
{
	return equippedWeapon;
}

void UPlayerInventory::SetBasicRifleBlueprint(TSubclassOf<class AWeapon> basicRifle)
{
	basicRifleBP = basicRifle;
}

void UPlayerInventory::SetAdvancedRifleBlueprint(TSubclassOf<class AWeapon> advancedRifle)
{
	advancedRifleBP = advancedRifle;
}

void UPlayerInventory::SetMachinePistolBlueprint(TSubclassOf<class AWeapon> machinePistol)
{
	machinePistolBP = machinePistol;
}