// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemies/EnemyCharacter.h"
#include "Stats/CharacterStats/MachinePistolerStats.h"
#include "MachinePistoler.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AMachinePistoler : public AEnemyCharacter
{
private:

	GENERATED_BODY()

protected:

	void SetStats() override;
	
};
