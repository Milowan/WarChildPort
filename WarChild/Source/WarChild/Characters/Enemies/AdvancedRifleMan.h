// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemies/EnemyCharacter.h"
#include "Stats/CharacterStats/AdvancedRifleManStats.h"
#include "AdvancedRifleMan.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AAdvancedRifleMan : public AEnemyCharacter
{
private:

	GENERATED_BODY()

protected:

	void SetStats() override;
	
};
