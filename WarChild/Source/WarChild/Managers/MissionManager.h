// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/Enemies/EnemyCharacter.h"
#include "Managers/AIManagerNew.h"
//#include "Managers/UIManager.h"
#include "Kismet/GameplayStatics.h"
#include "MissionManager.generated.h"

UCLASS()
class WARCHILD_API AMissionManager : public AActor
{
	GENERATED_BODY()
	

protected:

	UPROPERTY(EditAnywhere, Meta = (makeEditWidget = true), Category = "Spawns")
	FVector playerSpawnPoint;

	UPROPERTY(EditAnywhere, Meta = (makeEditWidget = true), Category = "Spawns")
	TArray<FVector> enemySpawnPoints;


	UPROPERTY(EditAnywhere, Category = "Spawns")
	TSubclassOf<class APlayerCharacter> playerBP;

	APlayerCharacter* player = 0;
	AAIManagerNew* aiManager = 0;
	//UUIManager* uiManager = 0;


public:	
	// Sets default values for this actor's properties
	AMissionManager();
	~AMissionManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Extract();


public:	

};
