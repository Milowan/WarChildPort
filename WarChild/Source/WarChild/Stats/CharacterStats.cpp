// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterStats.h"

float CharacterStats::GetMovSpeed()
{
	return movSpeed;
}

float CharacterStats::GetMaxHealth()
{
	return maxHealth;
}

float CharacterStats::GetCurrentHP()
{
	return currentHP;
}

float CharacterStats::GetArmour()
{
	return armour;
}

float CharacterStats::ReduceCurrentHP(float amount)
{
	currentHP -= amount;
	return currentHP;
}

void CharacterStats::SetCurrentHP(float amount)
{
	currentHP = amount;
}
