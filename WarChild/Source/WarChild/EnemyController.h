// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Types.h"
#include "Characters/Enemies/EnemyCharacter.h"
#include "Stats/CharacterStats/EnemyStats.h"
#include "DrawDebugHelpers.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AEnemyController : public AAIController
{
private:

	GENERATED_BODY()

	FRandomStream* stream;
	EnemyState state;
	float FoV;
	float sightRange;
	float rangeMax;
	float scanCD;
	float scanTimer;
	ABaseCharacter* target;


protected:

	virtual void OnMoveCompleted(FAIRequestID request, const FPathFollowingResult& result) override;
	virtual void BeginPlay() override;

public:

	AEnemyController();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetRandomDestination();

	void SetState(EnemyState nState);
	EnemyState GetState();

	UFUNCTION(BlueprintCallable)
	void SetRangeMax(float value);

	UFUNCTION(BlueprintCallable)
	float GetRangeMax();

};
