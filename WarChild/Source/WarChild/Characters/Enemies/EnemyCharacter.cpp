// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

int AEnemyCharacter::liveEnemies = 0;

AEnemyCharacter::AEnemyCharacter(const FObjectInitializer& ObjectInitializer) :
	AArmedCharacter(ObjectInitializer)
{}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

void AEnemyCharacter::CheckFire()
{

}

void AEnemyCharacter::Wander()
{

}

void AEnemyCharacter::Chase()
{

}

void AEnemyCharacter::Initialize(FTransform tf)
{
	SetActorTransform(tf);
	++liveEnemies;
}

void AEnemyCharacter::CheckTarget()
{

}

void AEnemyCharacter::SetTarget(ABaseCharacter target)
{

}

void AEnemyCharacter::Die()
{
	--liveEnemies;
}

int AEnemyCharacter::GetLiveEnemyCount()
{
	return liveEnemies;
}