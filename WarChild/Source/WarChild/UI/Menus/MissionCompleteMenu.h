// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menus/BaseMenu.h"
#include "MissionCompleteMenu.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UMissionCompleteMenu : public UBaseMenu
{
	GENERATED_BODY()

public:

	UMissionCompleteMenu(const FObjectInitializer& ObjectInitializer);
	~UMissionCompleteMenu();

	void OpenMenu();
	void CloseMenu();

	virtual void Back() override;
};
