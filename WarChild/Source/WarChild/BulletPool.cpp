// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletPool.h"

UBulletPool* UBulletPool::instance = NULL;

UBulletPool::~UBulletPool()
{
	instance = nullptr;
}

UBulletPool* UBulletPool::GetInstance()
{
	if (instance == NULL)
		instance = NewObject<UBulletPool>();

	return instance;
}

void UBulletPool::Release()
{
	instance = NULL;
}

void UBulletPool::SetWorld(UWorld* wrld)
{
	world = wrld;
}

void UBulletPool::FillPool()
{
	int poolSize = 80;

	for (int i = 0; i < poolSize; ++i)
	{
		pool.Add(Cast<ABullet>(world->SpawnActor(ABullet::StaticClass())));
	}
}

int UBulletPool::GetPoolSize()
{
	return pool.Num();
}

ABullet* UBulletPool::GetFreeBullet()
{
	ABullet* bullet = NULL;

	for (int i = 0; i < pool.Num(); ++i)
	{
		if (IsValid(pool[i]) && !pool[i]->IsActorTickEnabled())
		{
			bullet = pool[i];
			break;
		}
	}

	return bullet;
}