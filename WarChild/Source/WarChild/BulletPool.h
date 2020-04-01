// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "Bullet.h"
#include "BulletPool.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API UBulletPool : public UObject
{
private:

	GENERATED_BODY()

	TArray<ABullet*> pool;
	UWorld* world;
	static UBulletPool* instance;

public:

	static UBulletPool* GetInstance();
	static void Release();

	void SetWorld(UWorld* wrld);
	void FillPool();
	int GetPoolSize();

	ABullet* GetFreeBullet();
};
