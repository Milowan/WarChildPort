// Fill out your copyright notice in the Description page of Project Settings.


#include "DefenseMissionManager.h"




ADefenseMissionManager::ADefenseMissionManager()
	: Super()
{
	//playerSpawnPoint = FVector(0, 0, 10);
	waveCooldown = 5;
	cooldownTimer = 0;
	spawnCooldown = 3;
	spawnCooldownTimer = spawnCooldown;
	wave = 0;
	maxSpawn = 5;
	canSpawn = false;
	waveOver = false;
	addPerWave = 5;
}

ADefenseMissionManager::~ADefenseMissionManager()
{
}

void ADefenseMissionManager::BeginPlay()
{
	Super::BeginPlay();
	StartWave();
}

void ADefenseMissionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!canSpawn)
	{
		if (waveOver)
		{
			if (cooldownTimer >= waveCooldown)
			{
				StartWave();
			}
			else
			{
				cooldownTimer += DeltaTime;
			}
			if (wave % 5 == 0)
			{
				Extract();
			}
		}
	}
	else
	{
		if (cooldownTimer >= spawnCooldown)
		{
			AEnemyCharacter* enemy = Cast<AEnemyCharacter>(aiManager->GetInactiveEnemy());
			if (enemy)
			{
				//TArray<FTransform> spawnPoints = aiManager->GetSpawnPoints();
				//enemy->Initialize(spawnPoints[rand() + spawnPoints.Num() - 1]);
				enemy->Spawn();
				if (spawnCount == maxSpawn - 1)
				{
					//enemy->IsLast();
				}
			}
			cooldownTimer = 0.0f;
			spawnCount++;
			if (spawnCount >= maxSpawn)
			{
				canSpawn = false;
			}
			cooldownTimer += DeltaTime;
		}
	}
}

void ADefenseMissionManager::Extract()
{
	// GameEventManager->TriggerPause();
	// UIManager.OpenExtractMenu();
}

void ADefenseMissionManager::StartWave()
{
	wave++;
	maxSpawn += addPerWave;
	canSpawn = true;
	cooldownTimer = 0;
	// Set playerHud ObjectiveText to "Defend the Objective. Wave: wave"
}
