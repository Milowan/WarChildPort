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
private:

	GENERATED_BODY()

protected:

	virtual void NativeOnInitialized() override;

public:

	UMainMenu(const FObjectInitializer& ObjectInitializer);
	~UMainMenu();

	UFUNCTION()
	void OpenMenu();
	UFUNCTION()
	void CloseMenu();
};
