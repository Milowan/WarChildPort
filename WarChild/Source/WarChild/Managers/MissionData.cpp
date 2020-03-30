// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionData.h"

MissionData::MissionData()
{

}

MissionData::~MissionData()
{
}

void MissionData::AddToList(Mission mission)
{
	missions.push_back(mission);
}

void MissionData::Save()
{
	// I'll need gavin's help to implement saving and loading here
}

void MissionData::Load()
{
	// I'll need gavin's help to implement saving and loading here
}
