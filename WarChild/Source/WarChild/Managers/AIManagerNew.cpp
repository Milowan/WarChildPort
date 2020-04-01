// Fill out your copyright notice in the Description page of Project Settings.


#include "AIManagerNew.h"

// Sets default values
AAIManagerNew::AAIManagerNew()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
		//spawnPoints[i].SetLocation(aiPool[i]->GetActorLocation()); //I dont know why this line broke, lets see if I can run the build now?
	}
}

AAIManagerNew::~AAIManagerNew()
{
}

void AAIManagerNew::StartWithTarget(ACharacter* character)
{
	initialTarget = character;
}

TArray<FTransform> AAIManagerNew::GetSpawnPoints()
{
	return spawnPoints;
}

AActor * AAIManagerNew::GetInactiveEnemy()
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

int AAIManagerNew::GetPoolSize()
{
	return aiPool.Num();
}

// Called when the game starts or when spawned
void AAIManagerNew::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIManagerNew::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

