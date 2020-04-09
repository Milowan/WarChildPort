// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Managers/MissionManager.h"
#include "Characters/BaseCharacter.h"
#include "DefenseMissionManager.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API ADefenseMissionManager : public AMissionManager
{
	GENERATED_BODY()

private:

	float waveCooldown;
	float cooldownTimer;
	float spawnCooldown;
	float spawnCooldownTimer;
	int wave;
	int addPerWave;
	int maxSpawn;
	int spawnCount;
	bool waveOver;
	bool canSpawn;
	ABaseCharacter* defensePoint;
	FVector defensePointPos; //to become ADefensePoint reference instead

public:
	
	ADefenseMissionManager();
	~ADefenseMissionManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Extract() override;

private:

	void StartWave();
	
};
