// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menus/BaseMenu.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UPauseMenu : public UBaseMenu
{
private:

	GENERATED_BODY()

public:

	void OpenMenu();
	void CloseMenu();

	virtual void Back() override;
};
