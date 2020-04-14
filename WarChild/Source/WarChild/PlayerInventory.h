// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Weapon/Weapon.h"
#include "PlayerInventory.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UPlayerInventory : public UObject
{
private:

	GENERATED_BODY()

	static UPlayerInventory* instance;

	TSubclassOf<class AWeapon> equippedWeapon;

public:

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<class AWeapon> basicRifleBP;
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<class AWeapon> advancedRifleBP;
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<class AWeapon> machinePistolBP;

public:

	UPlayerInventory(const FObjectInitializer& OI);

	UFUNCTION(BlueprintCallable)
	static UPlayerInventory* GetInstance();
	UFUNCTION(BlueprintCallable)
	static void Release();

	UFUNCTION(BlueprintCallable)
	void SetEquippedWeapon(TSubclassOf<class AWeapon> weapon);
	UFUNCTION(BlueprintCallable)
	TSubclassOf<class AWeapon> GetEquippedWeapon();

	UFUNCTION(BlueprintCallable)
	void SetBasicRifleBlueprint(TSubclassOf<class AWeapon> basicRifle);
	UFUNCTION(BlueprintCallable)
	void SetAdvancedRifleBlueprint(TSubclassOf<class AWeapon> advancedRifle);
	UFUNCTION(BlueprintCallable)
	void SetMachinePistolBlueprint(TSubclassOf<class AWeapon> machinePistol);

	UFUNCTION(BlueprintCallable)
	TSubclassOf<class AWeapon> GetBasicRifleBlueprint();
	UFUNCTION(BlueprintCallable)
	TSubclassOf<class AWeapon> GetAdvancedRifleBlueprint();
	UFUNCTION(BlueprintCallable)
	TSubclassOf<class AWeapon> GetMachinePistolBlueprint();
};
