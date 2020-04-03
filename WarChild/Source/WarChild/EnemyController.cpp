// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"

AEnemyController::AEnemyController()
{
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
	stream = new FRandomStream(time(NULL));
}

void AEnemyController::Tick(float DeltaTime)
{
	if (GetState() == EnemyState::NONE)
	{
		SetState(EnemyState::WANDERING);
		SetRandomDestination();
	}
}

void AEnemyController::SetRandomDestination()
{
	FVector destination = FVector(stream->FRandRange(0, rangeMax), stream->FRandRange(0, rangeMax), stream->FRandRange(0, rangeMax));
	destination += GetPawn()->GetActorLocation();
	MoveToLocation(destination, 50.0f);
}

void AEnemyController::SetState(EnemyState nState)
{
	state = nState;
}

EnemyState AEnemyController::GetState()
{
	return state;
}