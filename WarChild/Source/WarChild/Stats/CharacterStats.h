// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class WARCHILD_API CharacterStats
{
protected:

	float maxHealth;
	float currentHP;
	float movSpeed;
	float armour;


public:

	float GetMovSpeed();
	float GetMaxHealth();
	float GetCurrentHP();
	float GetArmour();

	float ReduceCurrentHP(float amount);

	void SetCurrentHP(float amount);
};
