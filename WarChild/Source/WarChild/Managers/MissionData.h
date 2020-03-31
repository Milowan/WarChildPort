// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Managers/Mission.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "MissionData.generated.h"
/**
 * 
 */
UCLASS()
class WARCHILD_API UMissionData : public UObject//Data should be added to structs - its common convention
{
private:
	GENERATED_BODY()

	//Why not TArray? 
	//static std::vector<Mission> missions;
	TArray<AMission*> missions;



public:

	UMissionData();
	~UMissionData();

	TArray<AMission*> GetMissionArray();
	void AddToList(AMission mission);
	void Save();
	void Load();

};
