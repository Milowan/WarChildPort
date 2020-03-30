// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mission.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API AMission : public AActor
{
private:

	GENERATED_BODY()

	bool unlocked;
	bool completed;
	AMission* mNext;
	AMission* mPrev;
	std::string mName;


public:

	AMission(const FObjectInitializer& ObjectInitializer);
	AMission(std::string name, bool isUnlocked = false, AMission* prev = nullptr);
	~AMission();

	void SetNext(AMission* nMission);

	void Complete();

	void Unlock();

	std::string GetName();

};
