// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Managers/MissionManager.h"
#include "DefenseMissionManager.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API ADefenseMissionManager : public AMissionManager
{
	GENERATED_BODY()


public:

	virtual void Extract() override;
	
};
