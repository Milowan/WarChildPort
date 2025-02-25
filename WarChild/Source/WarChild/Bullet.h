// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionQueryParams.h"
#include "Characters/BaseCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Bullet.generated.h"

UCLASS()
class WARCHILD_API ABullet : public AActor
{
private:

	GENERATED_BODY()

	float flightSpeed;
	float damage;
	float lifeSpan;
	float age;
	FVector forward;
	USphereComponent* root;
	UStaticMeshComponent* bulletTrace;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this actor's properties
	ABullet();

	void Initialize(AActor* currentOwner, float speed, float dmg);
	void Despawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
