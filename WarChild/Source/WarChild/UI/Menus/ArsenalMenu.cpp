// Fill out your copyright notice in the Description page of Project Settings.


#include "ArsenalMenu.h"

UArsenalMenu::UArsenalMenu(const FObjectInitializer& ObjectInitializer)
	: UBaseMenu(ObjectInitializer)
{

}

UArsenalMenu::~UArsenalMenu()
{
}

void UArsenalMenu::NativeOnInitialized()
{
	UBaseMenu::NativeOnInitialized();

	//uiManager->OpenArsenal.AddDynamic(this, &UArsenalMenu::OpenMenu);
	//uiManager->CloseArsenal.AddDynamic(this, &UArsenalMenu::CloseMenu);

}

void UArsenalMenu::OpenMenu()
{
	AddToViewport(0);
}

void UArsenalMenu::CloseMenu()
{
	RemoveFromViewport();
}

void UArsenalMenu::Back()
{
	uiManager->CloseArsenal.Broadcast();
}