// Fill out your copyright notice in the Description page of Project Settings.


#include "AIManagerNew.h"



// Sets default values
AAIManagerNew::AAIManagerNew()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	poolSize = 30;
	aiPool.SetNum(poolSize);

	basicRiflemanBP = 0;
	advancedRiflemanBP = 0;
	machinePistolmanBP = 0;
	spawnRotation = FRotator(0, 180, 0);

	spawnParams = FActorSpawnParameters();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

AAIManagerNew::~AAIManagerNew()
{
}

void AAIManagerNew::StartWithTarget(ACharacter* character)
{
	//initialTarget = character;
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
	int temp = aiPool.Num();
	return temp;
}

// Called when the game starts or when spawned
void AAIManagerNew::BeginPlay()
{
	Super::BeginPlay();
	GenerateAI();
	
}

// Called every frame
void AAIManagerNew::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAIManagerNew::GenerateAI()
{
	int totalSize = aiPool.Num();
	for (int i = 0; i < totalSize; i++)
	{
		if (i < (totalSize / 3))
		{
			if (basicRiflemanBP)
			{
				UWorld* world = GetWorld();
				if (world)
				{
					FVector spawnPos = FVector(0, i * 40, 500);
					aiPool[i] = world->SpawnActor<ACharacter>(basicRiflemanBP, spawnPos, spawnRotation, spawnParams);
				}
			}
		}
		else if (i < (totalSize * 2 / 3))
		{
			if (advancedRiflemanBP)
			{
				UWorld* world = GetWorld();
				if (world)
				{
					FVector spawnPos = FVector(0, (i * 40) + 60, 500);
					aiPool[i] = world->SpawnActor<ACharacter>(advancedRiflemanBP, spawnPos, spawnRotation, spawnParams);
				}
			}
		}
		else
		{
			if (machinePistolmanBP)
			{
				UWorld* world = GetWorld();
				if (world)
				{
					FVector spawnPos = FVector(0, (i * 40) + 120, 500);
					aiPool[i] = world->SpawnActor<ACharacter>(machinePistolmanBP, spawnPos, spawnRotation, spawnParams);
				}
			}
		}
	}

}