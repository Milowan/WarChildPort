// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	lifeSpan = 2.0f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(false);
}

void ABullet::Initialize(FTransform start, FVector direction, float speed, float dmg)
{
	SetActorTickEnabled(true);
	SetActorTransform(start);
	forward = direction;
	flightSpeed = speed;
	damage = dmg;
}

void ABullet::Despawn()
{
	SetActorTickEnabled(false);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (age < lifeSpan)
	{
		age += DeltaTime;

		FHitResult hit;
		FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
		GetWorld()->LineTraceSingleByObjectType(OUT hit, GetActorLocation(), forward * flightSpeed, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

		AActor* aHit = hit.GetActor();

		if (aHit != NULL)
		{
			ABaseCharacter* character = Cast<ABaseCharacter>(aHit);

			if (character != NULL)
			{
				character->Damaged(damage);
			}
			Despawn();
		}

		SetActorLocation(GetActorLocation() + (forward * flightSpeed));
	}
	else
	{
		Despawn();
	}
}

