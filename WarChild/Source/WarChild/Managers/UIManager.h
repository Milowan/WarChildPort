// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIManager.generated.h"

UCLASS()
class WARCHILD_API AUIManager : public AActor
{
	GENERATED_BODY()
	
private:

	enum MenuTypes {NAV, ARSENAL, EXTRACT};
	TArray<MenuTypes> openMenus;

public:	
	// Sets default values for this actor's properties
	AUIManager(const FObjectInitializer& ObjectInitializer);
	~AUIManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Menu Functions
	void OpenNavigation();
	void CloseNavigation();
	void OpenArsenal();
	void CloseArsenal();
	void OpenExtraction();
	void CloseExctraction();

	void CloseCurrentMenu();

};
