// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

int AEnemyCharacter::liveEnemies = 0;

AEnemyCharacter::AEnemyCharacter(const FObjectInitializer& ObjectInitializer) :
	AArmedCharacter(ObjectInitializer)
{}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(false);
	USkeletalMeshComponent* mesh = GetMesh();
	mesh->SetVisibility(false);
	mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	equippedWeapon->GetMesh()->SetVisibility(false);
	
}

void AEnemyCharacter::Initialize(FTransform tf)
{
	SetActorTransform(tf);
	SetActorTickEnabled(true);
	active = true;
	USkeletalMeshComponent* mesh = GetMesh();
	mesh->SetVisibility(true);
	mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	equippedWeapon->GetMesh()->SetVisibility(true);
	++liveEnemies;
}

void AEnemyCharacter::Die()
{
	SetActorTickEnabled(false);
	active = false;
	USkeletalMeshComponent* mesh = GetMesh();
	mesh->SetVisibility(false);
	mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	equippedWeapon->GetMesh()->SetVisibility(false);
	--liveEnemies;
}

int AEnemyCharacter::GetLiveEnemyCount()
{
	return liveEnemies;
}