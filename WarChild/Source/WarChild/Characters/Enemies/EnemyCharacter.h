// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ArmedCharacter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AEnemyCharacter : public AArmedCharacter
{
private:

	GENERATED_BODY()

	FVector destination;
	float wanderRangeMin;
	float wanderRangeMax;
	bool alert;
	static int liveEnemies;

public:

	void CheckFire();
	void Wander();
	void Chase();
	void Initialize(FTransform tf);
	void CheckTarget();
	void SetTarget(ABaseCharacter target);
	void Die() override;

};
