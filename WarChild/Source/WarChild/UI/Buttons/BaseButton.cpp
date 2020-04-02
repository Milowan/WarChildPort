// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseButton.h"

UBaseButton::UBaseButton()
{

}

UBaseButton::~UBaseButton()
{

}

void UBaseButton::Activate()
{
	if (!uiManager)
	{
		TSubclassOf<AUIManager> uiManagerClass = 0;
		TArray<AActor*> uiManagerArray;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), uiManagerClass, uiManagerArray);
		if (uiManagerArray.Num() != 0)
		{
			uiManager = Cast<AUIManager>(uiManagerArray[0]);
		}
	}
}
