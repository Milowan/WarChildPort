// Fill out your copyright notice in the Description page of Project Settings.


#include "ExterminateMissionManager.h"

AExterminateMissionManager::AExterminateMissionManager()
	: Super()
{
	tickNum = 0;
	tickSpacer = 5;
	killGoal = 20;
	killCount = 0;
	liveEnemies = 0;
	maxLiving = 0;
}

AExterminateMissionManager::~AExterminateMissionManager()
{
}

void AExterminateMissionManager::BeginPlay()
{
	Super::BeginPlay();

	maxLiving = aiManager->GetPoolSize();
}

void AExterminateMissionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tickNum++;
	if (tickNum >= tickSpacer)
	{
		tickNum = 0;
		//Set playerHud objective text to "Slaughter the enemy! Killcount: killCount
		if (killCount >= killGoal)
		{
			Extract();
		}
		else if (liveEnemies < maxLiving)
		{
			AEnemyCharacter* enemy = Cast<AEnemyCharacter>(aiManager->GetInactiveEnemy());
			if (enemy)
			{
				int i = rand() * enemySpawnPoints.Num() - 1;
				if (i < 0 || i > (enemySpawnPoints.Num() - 1))
					i = 0;
				enemy->Place(FTransform(enemySpawnPoints[i]));
				enemy->SetActorLocation(enemySpawnPoints[i]);
			}
		}
	}
}

void AExterminateMissionManager::Extract()
{
	// SceneManager loadScene ("MissionComplete")  <----- switched to UIManager.OpenMissionComplete() or something??
}
