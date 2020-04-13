// Fill out your copyright notice in the Description page of Project Settings.


#include "ExtractMenu.h"

UExtractMenu::UExtractMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UExtractMenu::~UExtractMenu()
{
}

void UExtractMenu::OpenMenu()
{
	AddToViewport(0);
}

void UExtractMenu::CloseMenu()
{
	RemoveFromViewport();
}

void UExtractMenu::Back()
{

}