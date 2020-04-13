// Fill out your copyright notice in the Description page of Project Settings.


#include "NavMenu.h"


UNavMenu::UNavMenu(const FObjectInitializer& ObjectInitializer)
	: UBaseMenu(ObjectInitializer)
{
	// Set missionButtonContainer to... that (in unity it was a child component with other children)
}

UNavMenu::~UNavMenu()
{
}

void UNavMenu::NativeOnInitialized()
{
	UBaseMenu::NativeOnInitialized();

	//uiManager->OpenNavigation.AddDynamic(this, &UNavMenu::OpenMenu);
	//uiManager->CloseNavigation.AddDynamic(this, &UNavMenu::CloseMenu);
}

void UNavMenu::OpenMenu()
{
	AddToViewport(0);
}

void UNavMenu::CloseMenu()
{
	RemoveFromViewport();
}

void UNavMenu::SetMissionButtons()
{
	// for each button in missionButtonContainer
	// FText mButton = button.child component - text
	// for loop through MissionData.missions[]
	// if mButton.text == MissionData.missions[i].GetName()
	// Button.SetTargetLevel(MissionData.missions[i])
	// break
}

void UNavMenu::Back()
{
	uiManager->CloseNavigation.Broadcast();
}
