// Fill out your copyright notice in the Description page of Project Settings.


#include "Mission.h"


Mission::Mission(std::string name, bool isUnlocked, Mission* prev)
{
	mName = name;
	unlocked = isUnlocked;
	completed = false;
	mPrev = prev;

	if (prev != nullptr)
	{
		prev->SetNext(this);
		if (prev->completed)
			Unlock();
	}
}

Mission::~Mission()
{
}

void Mission::SetNext(Mission* nMission)
{
	mNext = nMission;
}

void Mission::Complete()
{
	completed = true;
	if (mNext != nullptr)
		mNext->Unlock();
}

void Mission::Unlock()
{
	unlocked = true;
}

std::string Mission::GetName()
{
	return mName;
}