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
	currentV = FVector::ZeroVector;
	
}

void AEnemyCharacter::Place(FTransform tf)
{
	FHitResult hit;
	SetActorTransform(tf, false, &hit, ETeleportType::TeleportPhysics);
	SetActorTickEnabled(true);
	active = true;
	USkeletalMeshComponent* mesh = GetMesh();
	mesh->SetVisibility(true);
	mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	equippedWeapon->GetMesh()->SetVisibility(true);
	stats->SetCurrentHP(stats->GetMaxHealth());
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

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	prevV = currentV;
	currentV = GetVelocity();

}

int AEnemyCharacter::GetLiveEnemyCount()
{
	return liveEnemies;
}

float AEnemyCharacter::GetAccelleration()
{
	return (currentV.Size() - prevV.Size()) / GetStats()->GetMovSpeed();
}