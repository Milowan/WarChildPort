// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicRifle.h"

ABasicRifle::ABasicRifle(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{}

void ABasicRifle::SetStats()
{
	stats = new BasicRifleStats();
}