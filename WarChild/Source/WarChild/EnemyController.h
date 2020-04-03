// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Characters/Enemies/EnemyCharacter.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AEnemyController : public AAIController
{
private:

	GENERATED_BODY()

	AEnemyCharacter* character;

protected:

	virtual void OnPossess(APawn* InPawn) override;

public:

	AEnemyController();

	virtual void Tick(float DeltaTime) override;

};
