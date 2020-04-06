// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	RootComponent = root;
	root->SetVisibility(false);
	root->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	mesh->SetupAttachment(RootComponent);
	mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (cdTimer < cooldown)
	{
		cdTimer += DeltaTime;
	}

	if (reloadTimer < stats->GetReloadSpeed())
	{
		reloadTimer += DeltaTime;
	}

	if (reloading)
	{
		Reload();
	}
	else
	{
		reloadTimer = 0.0f;
	}

}

void AWeapon::Destroyed()
{
	delete stats;

	UBulletPool::Release();
}

void AWeapon::Initialize()
{
	SetStats();
	pool = UBulletPool::GetInstance();
	if (pool->GetPoolSize() <= 0)
	{
		pool->SetWorld(GetWorld());
		pool->FillPool();
	}
	reloading = false;
	reloadTimer = 0.0f;
	currentClip = stats->GetClipSize();
	cooldown = 1 / stats->GetAttackSpeed();
	cdTimer = cooldown;
}

void AWeapon::Trigger()
{
	if (currentClip > 0)
	{
		if (cdTimer >= cooldown)
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
	if (currentClip > 0)
	{
		ABullet* bullet = pool->GetFreeBullet();

		if (bullet != NULL)
		{
			currentClip--;
			bullet->Initialize(this, stats->GetFlightSpeed(), stats->GetDamage());
			cdTimer = 0.0f;
		}
	}
}

void AWeapon::Reload()
{
	if (!(reloadTimer < stats->GetReloadSpeed()))
	{
		currentClip = stats->GetClipSize();
		reloading = false;
	}
}