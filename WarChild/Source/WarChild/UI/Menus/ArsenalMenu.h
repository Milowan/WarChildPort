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
	GENERATED_BODY()
	
public:

	UArsenalMenu();
	~UArsenalMenu();

	virtual void OpenMenu();
	virtual void CloseMenu();


};
