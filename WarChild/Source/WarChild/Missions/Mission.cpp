// Fill out your copyright notice in the Description page of Project Settings.


#include "Mission.h"


AMission::AMission(std::string name, bool isUnlocked, AMission* prev)
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

AMission::AMission(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

AMission::~AMission()
{
}

/*
	You shouldn't try to manage other missions within your mission class
	If you need to manage the missions create a manager class.

	Remember an object should only ever do one thing - missions should never set the next mission.
*/
void AMission::SetNext(AMission* nMission)
{
	mNext = nMission;
}

void AMission::Complete()
{
	completed = true;
	if (mNext != nullptr)
		mNext->Unlock();
}

void AMission::Unlock()
{
	unlocked = true;
}

std::string AMission::GetName()
{
	return mName;
}