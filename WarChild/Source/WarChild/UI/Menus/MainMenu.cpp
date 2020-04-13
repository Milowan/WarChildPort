// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"


UMainMenu::UMainMenu(const FObjectInitializer& ObjectInitializer)
	: UBaseMenu(ObjectInitializer)
{}

UMainMenu::~UMainMenu()
{}

void UMainMenu::NativeOnInitialized()
{
	UBaseMenu::NativeOnInitialized();

	//uiManager->OpenNavigation.AddDynamic(this, &UMainMenu::CloseMenu);
	//uiManager->CloseNavigation.AddDynamic(this, &UMainMenu::OpenMenu);
	//uiManager->OpenArsenal.AddDynamic(this, &UMainMenu::CloseMenu);
	//uiManager->CloseArsenal.AddDynamic(this, &UMainMenu::OpenMenu);
}

void UMainMenu::OpenMenu()
{
	AddToViewport(0);
}

void UMainMenu::CloseMenu()
{
	RemoveFromViewport();
}

