// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class WARCHILD_API WeaponStats
{
protected:

	float atkSp;
	float dmg;
	float flightSp;
	float reloadSp;
	float accuracy;		//1 being perfect, 0 never hitting center
	int clipSize;

public:

	float GetAttackSpeed();
	float GetDamage();
	float GetFlightSpeed();
	float GetReloadSpeed();
	float GetAccuracy();
	int GetClipSize();
};
