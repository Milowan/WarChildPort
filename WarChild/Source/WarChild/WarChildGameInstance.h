// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Weapon/Bullets/BulletPool.h"
#include "Managers/UIManager.h"
#include "PlayerInventory.h"
#include "WarChildGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UWarChildGameInstance : public UGameInstance
{
private:

	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	UBulletPool* bulletPool;
	UPROPERTY(VisibleAnywhere)
	UUIManager* uiManager;
	UPROPERTY(VisibleAnywhere)
	UPlayerInventory* playerInventory;

public:

	virtual void StartGameInstance() override;
	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void InitializeInventory();

	UFUNCTION(BlueprintCallable)
	UPlayerInventory* GetPlayerInventory();
	
};
