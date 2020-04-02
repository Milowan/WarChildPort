// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Buttons/BaseButton.h"
#include "OpenArsenal.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UOpenArsenal : public UBaseButton
{
	GENERATED_BODY()

private:

	UArsenalMenu* menu;

public:

	UOpenArsenal();
	~UOpenArsenal();

protected:

	virtual void Activate() override;

};
