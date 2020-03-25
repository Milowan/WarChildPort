// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"


class WARCHILD_API AIManager
{
private:
	UPROPERTY(EditAnywhere, Category = "Pool")
	int poolSize;

	TArray<AActor*> aiPool;   
	TArray <FTransform> spawnPoints;

	AActor* basicRiflemanBP;
	AActor* advancedRiflemanBP;
	AActor* machinePistolmanBP;
	ACharacter initialTarget;

public:
	AIManager();
	~AIManager();
	

protected:
	

};
