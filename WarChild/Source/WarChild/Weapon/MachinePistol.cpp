// Fill out your copyright notice in the Description page of Project Settings.


#include "MachinePistol.h"

AMachinePistol::AMachinePistol(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{}

void AMachinePistol::SetStats()
{
	stats = new MachinePistolStats();
}