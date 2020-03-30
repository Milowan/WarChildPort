// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Managers/Mission.h"
#include "Vector.h"
#include <vector>
#include "CoreMinimal.h"

/**
 * 
 */
class WARCHILD_API MissionData
{

private:

	static std::vector<Mission> missions;


public:

	MissionData();
	~MissionData();

	static void AddToList(Mission mission);
	static void Save();
	static void Load();

};
