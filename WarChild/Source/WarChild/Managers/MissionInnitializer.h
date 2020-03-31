// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Managers/MissionData.h"
#include "MissionInnitializer.generated.h"

UCLASS()
class WARCHILD_API AMissionInnitializer : public AActor
{
	GENERATED_BODY()

private:

	UMissionData* data;
	void GenerateMissions();

	
public:	
	// Sets default values for this actor's properties
	AMissionInnitializer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
