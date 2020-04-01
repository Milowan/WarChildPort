// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ArmedCharacter.h"
#include "Camera/CameraComponent.h"
#include "Managers/UIManager.h"
#include "GameFramework/SpringArmComponent.h"
#include "Stats/CharacterStats/PlayerStats.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARCHILD_API APlayerCharacter : public AArmedCharacter
{
private:

	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

protected:

	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void SetStats() override;

public:

	APlayerCharacter(const FObjectInitializer& ObjectInitializer);

	void Die() override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

};
