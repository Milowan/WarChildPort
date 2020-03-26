// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Stats/WeaponStats.h"
#include "Weapon.generated.h"

UCLASS()
class WARCHILD_API AWeapon : public AActor
{
private:

	GENERATED_BODY()

	UPROPERTY()
	UStaticMeshComponent* mesh;

	float deltaTime;

	bool reloading;
	float reloadTimer;
	float cooldown;
	float cdTimer;
	int currentClip;

protected:

	WeaponStats* stats;
	
protected:

	virtual void SetStats() PURE_VIRTUAL(AWeapon::SetStats, ;);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this actor's properties
	AWeapon();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Trigger();

	int InClip();


private:

	void Fire();
	void Reload();

};
