// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menus/BaseMenu.h"
#include "ExtractMenu.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UExtractMenu : public UBaseMenu
{
	GENERATED_BODY()
	
public:

	UExtractMenu(const FObjectInitializer& ObjectInitializer);
	~UExtractMenu();

	void OpenMenu();
	void CloseMenu();

	virtual void Back() override;
};
