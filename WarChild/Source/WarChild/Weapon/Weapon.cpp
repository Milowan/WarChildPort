// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon()
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
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if reloading then reload

}

void AWeapon::Trigger()
{

}

int AWeapon::InClip()
{
	return 0;
}

void AWeapon::Fire()
{

}

void AWeapon::Reload()
{

}