// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Managers/MissionManager.h"
#include "ExterminateMissionManager.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AExterminateMissionManager : public AMissionManager
{
	GENERATED_BODY()

private:

	int killGoal;
	int killCount;
	int liveEnemies;
	int maxLiving;
	int tickSpacer;
	int tickNum;
	
public:

	AExterminateMissionManager();
	~AExterminateMissionManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Extract() override;
};
