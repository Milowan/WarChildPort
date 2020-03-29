// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>
#include "CoreMinimal.h"

/**
 * 
 */
class WARCHILD_API Mission
{

private:

	bool unlocked;
	bool completed;
	Mission* mNext;
	Mission* mPrev;
	std::string mName;




public:

	Mission(std::string name, bool isUnlocked = false, Mission* prev = nullptr);
	~Mission();

	void SetNext(Mission* nMission);

	void Complete();

	void Unlock();

	std::string GetName();

};
