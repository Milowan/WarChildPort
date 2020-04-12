// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"

void UPauseMenu::OpenPauseMenu()
{
	AddToViewport(0);
}

void UPauseMenu::ClosePauseMenu()
{
	RemoveFromViewport();
}