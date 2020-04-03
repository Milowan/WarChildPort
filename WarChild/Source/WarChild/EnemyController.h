// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Math/RandomStream.h"
#include <time.h>
#include "Types.h"
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
	const float rangeMax = 200.0f;
	EnemyState state;

protected:

	virtual void OnMoveCompleted(FAIRequestID request, const FPathFollowingResult& result) override;
	virtual void BeginPlay() override;

public:

	AEnemyController();

	virtual void Tick(float DeltaTime) override;

	void SetRandomDestination();

	void SetState(EnemyState nState);
	EnemyState GetState();

};
