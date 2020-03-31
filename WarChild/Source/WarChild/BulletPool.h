// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"

/**
 * 
 */
class WARCHILD_API BulletPool
{
private:

	TArray<ABullet*> pool;
	UWorld* world;
	static BulletPool* instance;

public:

	static BulletPool* GetInstance();
	static void Release();

	void SetWorld(UWorld* wrld);

	ABullet* GetFreeBullet();

private:

	BulletPool();
};
