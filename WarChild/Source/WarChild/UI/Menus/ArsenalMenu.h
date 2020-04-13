// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menus/BaseMenu.h"
#include "ArsenalMenu.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UArsenalMenu : public UBaseMenu
{
private:

	GENERATED_BODY()

protected:

	virtual void NativeOnInitialized() override;
	
public:

	UArsenalMenu(const FObjectInitializer& ObjectInitializer);
	~UArsenalMenu();

	UFUNCTION()
	void OpenMenu();
	UFUNCTION()
	void CloseMenu();

	virtual void Back() override;
};
