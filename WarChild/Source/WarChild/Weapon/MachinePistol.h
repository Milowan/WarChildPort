// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Weapon.h"
#include "Stats/WeaponStats/MachinePistolStats.h"
#include "MachinePistol.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AMachinePistol : public AWeapon
{
private:

	GENERATED_BODY()

protected:

	void SetStats() override;
	
};
