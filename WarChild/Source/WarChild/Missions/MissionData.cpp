// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionData.h"
#include "Mission.h"

UMissionData::UMissionData()
	: Super()
{

}

UMissionData::~UMissionData()
{
}

TArray<AMission*> UMissionData::GetMissionArray()
{
	return missions;
}

void UMissionData::AddToList(AMission mission)
{
	//missions.push_back(mission);
	missions.Add(&mission);
}

void UMissionData::Save()
{
	// I'll need Gavin's help to implement saving and loading here
}

void UMissionData::Load()
{
	// I'll need Gavin's help to implement saving and loading here
}
