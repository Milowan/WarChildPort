// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Weapon.h"
#include "Stats/WeaponStats/BasicRifleStats.h"
#include "BasicRifle.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API ABasicRifle : public AWeapon
{
private:

	GENERATED_BODY()
	
protected:

	void SetStats() override;

public:

	ABasicRifle(const FObjectInitializer& ObjectInitializer);

};
