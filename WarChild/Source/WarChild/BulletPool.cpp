// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletPool.h"

BulletPool* BulletPool::instance = NULL;

BulletPool* BulletPool::GetInstance()
{
	if (instance == NULL)
		instance = new BulletPool();

	return instance;
}

void BulletPool::Release()
{
	delete instance;
	instance = NULL;
}

BulletPool::BulletPool()
{
	int poolSize = 80;

	for (int i = 0; i < poolSize; ++i)
	{
		pool.Add(Cast<ABullet>(world->SpawnActor(ABullet::StaticClass())));
	}
}

void BulletPool::SetWorld(UWorld* wrld)
{
	world = wrld;
}

ABullet* BulletPool::GetFreeBullet()
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