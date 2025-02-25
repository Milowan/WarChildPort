// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Stats/WeaponStats/WeaponStats.h"
#include "BulletPool.h"
#include "Weapon.generated.h"

UCLASS(BlueprintType)
class WARCHILD_API AWeapon : public AActor
{
private:

	GENERATED_BODY()

	bool reloading;
	float reloadTimer;
	float cooldown;
	float cdTimer;
	int currentClip;

	UBulletPool* pool;

	USphereComponent* root;

protected:

	WeaponStats* stats;

public:

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon|Mesh")
	UStaticMeshComponent* mesh;

private:

	void Fire();
	void Reload();
	
protected:

	virtual void SetStats() PURE_VIRTUAL(AWeapon::SetStats, ;);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this actor's properties
	AWeapon(const FObjectInitializer& ObjectInitializer);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Destroyed() override;

	UFUNCTION(BlueprintCallable)
	void Initialize();

	void Trigger();

	int InClip();

	UStaticMeshComponent* GetMesh();

};
