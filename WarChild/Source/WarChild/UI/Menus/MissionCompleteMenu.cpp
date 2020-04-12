// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionCompleteMenu.h"


UMissionCompleteMenu::UMissionCompleteMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UMissionCompleteMenu::~UMissionCompleteMenu()
{
}

void UMissionCompleteMenu::OpenMenu()
{
	AddToViewport(0);
	// MissionTracker->CurrentMission->Complete();
	// MissionData->Save();
}

void UMissionCompleteMenu::CloseMenu()
{
	RemoveFromViewport();
}
