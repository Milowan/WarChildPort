// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenArsenal.h"


UOpenArsenal::UOpenArsenal()
{

}

UOpenArsenal::~UOpenArsenal()
{

}

void UOpenArsenal::Activate()
{
	UUIManager::GetInstance()->OpenArsenal.Broadcast();
}
