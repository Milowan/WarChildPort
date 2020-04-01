// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "AIManagerNew.generated.h"

UCLASS()
class WARCHILD_API AAIManagerNew : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Pool")
		int poolSize;

	TArray<AActor*> aiPool;
	TArray <FTransform> spawnPoints;

	AActor* basicRiflemanBP;
	AActor* advancedRiflemanBP;
	AActor* machinePistolmanBP;
	ACharacter* initialTarget;

public:
	AAIManagerNew();
	~AAIManagerNew();
	void StartWithTarget(ACharacter* character); // Change to ACharacter when built
	TArray<FTransform> GetSpawnPoints();
	AActor* GetInactiveEnemy(); // Change to AEnemy when built
	int GetPoolSize();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


};
