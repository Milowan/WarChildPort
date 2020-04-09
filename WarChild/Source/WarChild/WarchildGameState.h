// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "WarchildGameState.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameEvent);

UCLASS()
class WARCHILD_API AWarchildGameState : public AGameStateBase
{
private:

	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintAssignable)
	FGameEvent OnGameStart;
	UPROPERTY(BlueprintAssignable)
	FGameEvent OnGameOver;
	UPROPERTY(BlueprintAssignable)
	FGameEvent OnPause;
	UPROPERTY(BlueprintAssignable)
	FGameEvent OnUnPause;

};
