// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UIManager.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUIManager : public UInterface
{
	GENERATED_BODY()

private:
	// Add variable to hold which menu is currently open

public:

	void CloseCurrentMenu();


};

/**
 * 
 */
class WARCHILD_API IUIManager
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// CLASSES THAT WANT TO USE THIS EVENT MANAGER:
	// Class must inherit from IUIManager
	// Classes must publicly define all events (even by leaving them empty) or it will cause errors.
	void OpenNavigation();
	void CloseNavigation();
	void OpenArsenal();
	void CloseArsenal();
	void OpenExtraction();
	void CloseExctraction();

};
