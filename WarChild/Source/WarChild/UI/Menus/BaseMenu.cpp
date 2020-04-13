// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMenu.h"
//UBaseMenu::UBaseMenu()
//{
//
//}

UBaseMenu::UBaseMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UBaseMenu::~UBaseMenu()
{
}

void UBaseMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	uiManager = UUIManager::GetInstance();
}

void UBaseMenu::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UWorld* world = GetWorld();
	if (world->GetFirstPlayerController()->WasInputKeyJustPressed(FKey(FName(TEXT("Q")))))
	{
		Back();
	}
}