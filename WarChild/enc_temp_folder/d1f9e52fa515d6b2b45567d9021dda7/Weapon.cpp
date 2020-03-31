// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	reloading = false;
	reloadTimer = 0.0f;
	SetStats();
	currentClip = stats->GetClipSize();
	cooldown = 1 / stats->GetAttackSpeed();
	cdTimer = cooldown;
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	deltaTime = DeltaTime;

	if (reloading)
	{
		Reload();
	}
	else
	{
		reloadTimer = 0.0f;
	}

}

void AWeapon::Trigger()
{
	if (currentClip > 0)
	{
		if (cdTimer < cooldown)
		{
			cdTimer += deltaTime;
		}
		else
		{
			Fire();
		}
	}
	else
	{
		reloading = true;
	}
}

int AWeapon::InClip()
{
	return currentClip;
}

void AWeapon::Fire()
{
	//shoot bullet
	//GetActorForwardVector();
}

void AWeapon::Reload()
{
	if (reloadTimer < stats->GetReloadSpeed())
	{
		reloadTimer += deltaTime;
	}
	else
	{
		currentClip = stats->GetClipSize();
		reloading = false;
	}
}