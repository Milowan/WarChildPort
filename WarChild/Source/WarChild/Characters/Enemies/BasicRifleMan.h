// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemies/EnemyCharacter.h"
#include "Stats/CharacterStats/BasicRifleManStats.h"
#include "BasicRifleMan.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API ABasicRifleMan : public AEnemyCharacter
{
private:

	GENERATED_BODY()

protected:

	void SetStats() override;
	
};
