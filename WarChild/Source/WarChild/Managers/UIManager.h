// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Missions/MissionTracker.h"

#include "UIManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUIEvent);

UCLASS()
class WARCHILD_API UUIManager : public UObject
{
private:

	GENERATED_BODY()

	// Sets default values for this actor's properties
	UUIManager(const FObjectInitializer& ObjectInitializer);
	~UUIManager();

	static UUIManager* instance;
	
public:	

	UFUNCTION(BlueprintCallable)
	static UUIManager* GetInstance();
	UFUNCTION(BlueprintCallable)
	static void Release();

	// Menu Functions
	UPROPERTY(BlueprintAssignable)
	FUIEvent OpenNavigation;
	UPROPERTY(BlueprintAssignable)
	FUIEvent CloseNavigation;
	UPROPERTY(BlueprintAssignable)
	FUIEvent OpenArsenal;
	UPROPERTY(BlueprintAssignable)
	FUIEvent CloseArsenal;
	UPROPERTY(BlueprintAssignable)
	FUIEvent OpenExtraction;
	UPROPERTY(BlueprintAssignable)
	FUIEvent CloseExctraction;


};
