// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InputManager.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInputManager : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WARCHILD_API IInputManager
{
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:

	// CLASSES THAT WANT TO USE THIS EVENT MANAGER:
	// Class must inherit from IInputManager
	// Classes must publicly define all events (even by leaving them empty) or it will cause errors.

	// Need to take a meeting to figure out what all our inputs will be and what is handled by this manager
	void OnButtonDownSpace();
	void OnButtonUpSpace();
	// We need these for every input?



};
