// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"

AEnemyController::AEnemyController()
{
	rangeMax = 2000.0f;
}

void AEnemyController::OnMoveCompleted(FAIRequestID request, const FPathFollowingResult& result)
{
	if (GetState() == EnemyState::WANDERING)
	{
		SetRandomDestination();
	}
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyController::Tick(float DeltaTime)
{
	if (GetPawn()->IsActorTickEnabled())
	{
		if (GetState() == EnemyState::NONE)
		{
			SetState(EnemyState::WANDERING);
			SetRandomDestination();
		}
	}
}

void AEnemyController::SetState(EnemyState nState)
{
	state = nState;
}

EnemyState AEnemyController::GetState()
{
	return state;
}

void AEnemyController::SetRangeMax(float value)
{
	rangeMax = value;
}

float AEnemyController::GetRangeMax()
{
	return rangeMax;
}