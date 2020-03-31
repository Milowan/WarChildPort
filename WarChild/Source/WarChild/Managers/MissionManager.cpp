// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionManager.h"

// Sets default values
AMissionManager::AMissionManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AMissionManager::~AMissionManager()
{
}

// Called when the game starts or when spawned
void AMissionManager::BeginPlay()
{
	Super::BeginPlay();
	TSubclassOf<APlayerCharacter> playerClass = 0;
	TArray<AActor*> playerArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), playerClass, playerArray);

	if (playerArray.Num() != 0)
	{
		player = Cast<APlayerCharacter>(playerArray[0]);
		player->SetActorLocation(playerSpawnPoint, false);
	}

}

void AMissionManager::Extract()
{
}

// Called every frame
void AMissionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

