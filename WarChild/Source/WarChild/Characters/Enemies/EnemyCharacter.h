// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ArmedCharacter.h"
#include "Components/SkeletalMeshComponent.h"
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

protected:

	virtual void BeginPlay() override;

public:

	AEnemyCharacter(const FObjectInitializer& ObjectInitializer);

	void Place(FTransform tf);
	void Die() override;

	static int GetLiveEnemyCount();

};
