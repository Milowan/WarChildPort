// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Managers/UIManager.h"


#include "Components/Button.h"
#include "BaseButton.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UBaseButton : public UButton
{
	GENERATED_BODY()
	

private:

	AUIManager* uiManager;


public:

	UBaseButton();
	~UBaseButton();

protected:

	UFUNCTION(BlueprintCallable)
	virtual void Activate();


};
