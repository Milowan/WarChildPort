// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionInnitializer.h"

void AMissionInnitializer::GenerateMissions()
{
	//come back to these when missions are done
	//data->AddToList(DefenseMission, true);
	//data->AddToList(ExterminateMission, false, data->GetMissionArray()[0]);
	//data->AddToList(3rdMissionType, stuff);
}

// Sets default values
AMissionInnitializer::AMissionInnitializer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	data = CreateDefaultSubobject<UMissionData>("Data");

}

// Called when the game starts or when spawned
void AMissionInnitializer::BeginPlay()
{
	Super::BeginPlay();

	data->Load();
	if (data->GetMissionArray().Num() == 0)
	{
		GenerateMissions();
	}
	// Load "Main Menu" scene
}

// Called every frame
void AMissionInnitializer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

