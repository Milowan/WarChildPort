// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"

AEnemyController::AEnemyController()
{
	character = NULL;
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	character = Cast<AEnemyCharacter>(InPawn);
}

void AEnemyController::Tick(float DeltaTime)
{

}