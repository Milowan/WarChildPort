// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
#include "Characters/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MissionManager.generated.h"

UCLASS()
class WARCHILD_API AMissionManager : public AActor
{
	GENERATED_BODY()
	
private:
	FVector playerSpawnPoint = FVector();
	APlayerCharacter* player = 0;

public:	
	// Sets default values for this actor's properties
	AMissionManager();
	~AMissionManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Extract();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
