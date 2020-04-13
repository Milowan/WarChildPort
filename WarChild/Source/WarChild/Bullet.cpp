// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	lifeSpan = 2.0f;

	root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	RootComponent = root;
	root->SetVisibility(false);
	root->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	bulletTrace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletTracer"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/GrayBoxKit/Source/Meshes/SM_Bullet.SM_Bullet'"));
	UStaticMesh* Asset = MeshAsset.Object;
	bulletTrace->SetStaticMesh(Asset);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(false);
}

void ABullet::Initialize(AActor* weapon, float speed, float dmg)
{
	SetActorTickEnabled(true);
	FHitResult hit;
	forward = weapon->GetActorForwardVector();
	SetActorLocation(weapon->GetActorLocation() + (forward * 50), false, &hit, ETeleportType::TeleportPhysics);
	flightSpeed = speed;
	damage = dmg;
	age = 0.0f;
}

void ABullet::Despawn()
{
	bulletTrace->SetVisibility(false);
	SetActorTickEnabled(false);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (age < lifeSpan)
	{
		bulletTrace->SetVisibility(true);
		age += DeltaTime;
		FVector position = GetActorLocation();
		bulletTrace->AddWorldTransform(FTransform(position));

		FHitResult hit;
		FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
		GetWorld()->LineTraceSingleByObjectType(OUT hit, position, position + forward * flightSpeed, FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn), TraceParams);

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

		aHit = NULL;

		GetWorld()->LineTraceSingleByObjectType(OUT hit, position, position + forward * flightSpeed, FCollisionObjectQueryParams(ECollisionChannel::ECC_OverlapAll_Deprecated), TraceParams);
		aHit = hit.GetActor();

		if (aHit != NULL)
		{
			Despawn();
		}

		SetActorLocation(GetActorLocation() + (forward * flightSpeed));
	}
	else
	{
		Despawn();
	}
}

