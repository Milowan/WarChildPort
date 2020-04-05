// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Components/SphereComponent.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Character.h"
#include "AIManagerNew.generated.h"

UCLASS()
class WARCHILD_API AAIManagerNew : public AActor
{
	GENERATED_BODY()
	
private:

	FActorSpawnParameters spawnParams;

	UPROPERTY(EditAnywhere, Category = "Pool")
		int poolSize;

	UPROPERTY(EditAnywhere, Category = "Spawn")
		FRotator spawnRotation;

	//UPROPERTY(EditAnywhere, Category = "Spawn")
	//	UArrowComponent* basicRifleSpawnPoint;

	//UPROPERTY(EditAnywhere, Category = "Spawn")
	//	USphereComponent* advRifleSpawnPoint;

	//UPROPERTY(EditAnywhere, Category = "Spawn")
	//	USphereComponent* machPistolSpawnPoint;


private:

	void GenerateAI();

public:

	UPROPERTY(EditAnywhere, Category = "Pool")
		TSubclassOf<class ACharacter> basicRiflemanBP;

	UPROPERTY(EditAnywhere, Category = "Pool")
		TSubclassOf<class ACharacter> advancedRiflemanBP;

	UPROPERTY(EditAnywhere, Category = "Pool")
		TSubclassOf<class ACharacter> machinePistolmanBP;

	UPROPERTY(EditAnywhere, Category = "Pool")
	TArray<AActor*> aiPool;

public:
	AAIManagerNew();
	~AAIManagerNew();
	void StartWithTarget(ACharacter* character); // Change to ACharacter when built
	AActor* GetInactiveEnemy(); // Change to AEnemy when built
	// need new getSpawnPoints function when spawn points are figured out
	int GetPoolSize();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


};
