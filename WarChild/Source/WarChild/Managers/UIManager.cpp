// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

// Sets default values
AUIManager::AUIManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AUIManager::~AUIManager()
{
}

// Called when the game starts or when spawned
void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUIManager::OpenNavigation()
{
	openMenus.Add(MenuTypes::NAV);
}

void AUIManager::CloseNavigation()
{
	openMenus.RemoveAt(openMenus.Num());
}

void AUIManager::OpenArsenal()
{
	openMenus.Add(MenuTypes::ARSENAL);
}

void AUIManager::CloseArsenal()
{
	openMenus.RemoveAt(openMenus.Num());
}

void AUIManager::OpenExtraction()
{
	openMenus.Add(MenuTypes::EXTRACT);
}

void AUIManager::CloseExctraction()
{
	openMenus.RemoveAt(openMenus.Num());
}

void AUIManager::CloseCurrentMenu()
{
	switch (openMenus.Last())
	{
	case NAV:
		CloseNavigation();
		break;
	case ARSENAL:
		CloseArsenal();
		break;
	case EXTRACT:
		CloseExctraction();
		break;
	default:
		break;
	}
}

