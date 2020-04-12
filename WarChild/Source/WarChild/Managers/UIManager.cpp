// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

UUIManager* UUIManager::instance = NULL;

// Sets default values
UUIManager::UUIManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{}

UUIManager::~UUIManager()
{}

UUIManager* UUIManager::GetInstance()
{
	if (instance == NULL)
		instance = NewObject<UUIManager>();
	return instance;
}

void UUIManager::Release()
{
	instance = NULL;
}
