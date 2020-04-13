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

protected:

	virtual void NativeOnInitialized() override;

public:

	UNavMenu(const FObjectInitializer& ObjectInitializer);
	~UNavMenu();

	UFUNCTION()
	void OpenMenu();
	UFUNCTION()
	void CloseMenu();

	virtual void Back() override;

private:

	void SetMissionButtons();

};
