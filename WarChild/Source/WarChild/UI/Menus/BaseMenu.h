// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "Managers/UIManager.h"
#include "BaseMenu.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UBaseMenu : public UUserWidget
{
private:

	GENERATED_BODY()

protected:

	typedef UUserWidget Super;

	UUIManager* uiManager;

	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:

	//UBaseMenu();
	UBaseMenu(const FObjectInitializer& ObjectInitializer);
	~UBaseMenu();

	virtual void Back() PURE_VIRTUAL(&UBaseMenu::Back, ;);
};
