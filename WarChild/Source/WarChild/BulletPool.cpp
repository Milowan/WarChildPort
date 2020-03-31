// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletPool.h"

UBulletPool* UBulletPool::instance = NULL;

UBulletPool* UBulletPool::GetInstance()
{
	if (instance == NULL)
		instance = NewObject<UBulletPool>();

	if (instance->pool.Num() <= 0)
	{
		instance->FillPool();
	}

	return instance;
}

void UBulletPool::Release()
{
	delete instance;
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

ABullet* UBulletPool::GetFreeBullet()
{
	ABullet* bullet = NULL;

	for (int i = 0; i < pool.Num(); ++i)
	{
		if (!pool[i]->IsActorTickEnabled())
		{
			bullet = pool[i];
			break;
		}
	}

	return bullet;
}