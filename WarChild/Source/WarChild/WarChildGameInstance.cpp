// Fill out your copyright notice in the Description page of Project Settings.


#include "WarChildGameInstance.h"

void UWarChildGameInstance::StartGameInstance()
{
	bulletPool = UBulletPool::GetInstance();
	uiManager = UUIManager::GetInstance();
	playerInventory = UPlayerInventory::GetInstance();

	InitializeInventory();
}

void UWarChildGameInstance::Shutdown()
{
	UBulletPool::Release();
	UUIManager::Release();
	UPlayerInventory::Release();
}

UPlayerInventory* UWarChildGameInstance::GetPlayerInventory()
{
	return playerInventory;
}