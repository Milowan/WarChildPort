// Fill out your copyright notice in the Description page of Project Settings.


#include "AIManager.h"

AIManager::AIManager()
{
	poolSize = 30;
	aiPool.SetNum(poolSize);
	for (int i = 0; i < aiPool.Num(); i++)
	{
		if (i < poolSize / 3)
		{
			// Change these ifs to create new versions of this bp not just copy the bp
			aiPool[i] = basicRiflemanBP;

		}
		else if (i < poolSize * (2 / 3))
		{
			aiPool[i] = advancedRiflemanBP;
		}
		else
		{
			aiPool[i] = machinePistolmanBP;
		}
	}

	spawnPoints.SetNum(aiPool.Num());
	for (int i = 0; i < spawnPoints.Num(); i++)
	{
		// Possibly convert this to spawn points being children of this manager instead of just the aiPool.Num()
		spawnPoints[i].SetLocation(aiPool[i]->GetActorLocation());
	}
}

AIManager::~AIManager()
{
}

void AIManager::StartWithTarget(ACharacter* character)
{
	initialTarget = character;
}

TArray<FTransform> AIManager::GetSpawnPoints()
{
	return spawnPoints;
}

AActor * AIManager::GetInactiveEnemy()
{
	AActor* tempEnemy = 0;
	for (int i = 0; i < aiPool.Num(); i++)
	{
		if (aiPool[i]->IsActorTickEnabled())
		{
			tempEnemy = aiPool[i];
			// tempEnemy->SetTarget(initialTarget);
			break;
		}
	}
	return tempEnemy;
}

int AIManager::GetPoolSize()
{
	return aiPool.Num();
}
