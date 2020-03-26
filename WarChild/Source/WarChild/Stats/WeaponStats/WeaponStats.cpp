// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponStats.h"

float WeaponStats::GetAttackSpeed()
{
	return atkSp;
}

float WeaponStats::GetDamage()
{
	return dmg;
}

float WeaponStats::GetFlightSpeed()
{
	return flightSp;
}

float WeaponStats::GetReloadSpeed()
{
	return reloadSp;
}

float WeaponStats::GetAccuracy()
{
	return accuracy;
}

int WeaponStats::GetClipSize()
{
	return clipSize;
}
