// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"

void UPauseMenu::OpenMenu()
{
	AddToViewport(0);
}

void UPauseMenu::CloseMenu()
{
	RemoveFromViewport();
}

void UPauseMenu::Back()
{

}