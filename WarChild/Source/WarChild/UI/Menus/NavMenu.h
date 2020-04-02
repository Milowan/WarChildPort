// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menus/BaseMenu.h"
#include "NavMenu.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UNavMenu : public UBaseMenu
{
	GENERATED_BODY()

private:

	FTransform missionButtonContainer;

public:

	UNavMenu(const FObjectInitializer& ObjectInitializer);
	~UNavMenu();

	virtual void OpenMenu();
	virtual void CloseMenu();

private:

	void SetMissionButtons();

};
