// Fill out your copyright notice in the Description page of Project Settings.


#include "NavMenu.h"


UNavMenu::UNavMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set missionButtonContainer to... that (in unity it was a child component with other children)
}

UNavMenu::~UNavMenu()
{
}

void UNavMenu::OpenMenu()
{
}

void UNavMenu::CloseMenu()
{
}

void UNavMenu::SetMissionButtons()
{
	// for each button in missionButtonContainer
	// FText mButton = button.child component - text
	// for loop through MissionData.missions[]
	// if mButton.text == MissionData.missions[i].GetName()
	// Button.SetTargetLevel(MissionData.missions[i]
	// break
}
