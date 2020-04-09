// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionManager.h"

// Sets default values
AMissionManager::AMissionManager()
	: Super()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	playerSpawnPoint = FVector();
}

AMissionManager::~AMissionManager()
{
}

// Called when the game starts or when spawned
void AMissionManager::BeginPlay()
{
	Super::BeginPlay();

	TSubclassOf<APlayerCharacter> playerClass = APlayerCharacter::StaticClass();
	TArray<AActor*> playerArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), playerClass, playerArray);
	if (playerArray.Num() != 0)
	{
		player = Cast<APlayerCharacter>(playerArray[0]);
		player->SetActorLocation(playerSpawnPoint, false);
	}

	TSubclassOf<AAIManagerNew> aiManagerClass = AAIManagerNew::StaticClass();
	TArray<AActor*> aiManagerArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), aiManagerClass, aiManagerArray);
	if (aiManagerArray.Num() != 0)
	{
		aiManager = Cast<AAIManagerNew>(aiManagerArray[0]);
	}


}

void AMissionManager::Extract()
{
	// Figure out how to trigger event calls from:
	// GameEventManager    (TriggerPause)
	// UIManager           (OpenMenu)
}

// Called every frame
void AMissionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

