// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedRifle.h"

AAdvancedRifle::AAdvancedRifle(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{}

void AAdvancedRifle::SetStats()
{
	stats = new AdvancedRifleStats();
}