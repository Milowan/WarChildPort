// Fill out your copyright notice in the Description page of Project Settings.


#include "AIManager.h"

AIManager::AIManager()
{
	poolSize = 30;
	aiPool.SetNum(poolSize);
	for (int i = 0; i < aiPool.Num(); i++)
	{
		if (i < poolSize / 3)
		{
			// Change these ifs to create new versions of this bp not just copy the bp
			aiPool[i] = basicRiflemanBP;

		}
		else if (i < poolSize * (2 / 3))
		{
			aiPool[i] = advancedRiflemanBP;
		}
		else
		{
			aiPool[i] = machinePistolmanBP;
		}
	}

	spawnPoints.SetNum(aiPool.Num());

}

AIManager::~AIManager()
{
}
