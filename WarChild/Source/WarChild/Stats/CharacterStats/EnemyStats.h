// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterStats.h"
#include "CoreMinimal.h"

/**
 * 
 */
class WARCHILD_API EnemyStats : public CharacterStats
{
protected:

	float effectiveRange;

public:

    float GetRange();

};
