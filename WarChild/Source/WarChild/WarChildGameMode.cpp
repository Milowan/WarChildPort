// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "WarChildGameMode.h"
#include "Characters/PlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWarChildGameMode::AWarChildGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/PlayerCharacterBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
