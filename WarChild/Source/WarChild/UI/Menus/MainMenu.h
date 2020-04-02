// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menus/BaseMenu.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UMainMenu : public UBaseMenu
{
	GENERATED_BODY()

public:

	UMainMenu(const FObjectInitializer& ObjectInitializer);
	~UMainMenu();

	virtual void OpenMenu();
	virtual void CloseMenu();


};
