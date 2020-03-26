// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Stats/CharacterStats/PlayerStats.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
[event_receiver(native)]
class WARCHILD_API APlayerCharacter : public ABaseCharacter
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

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:

	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void SetStats() override;

public:

	APlayerCharacter();

	void Die() override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


	// This is a function that executes with the MyEvent event from CharacterController.
	void MyEventHandler(int nValue);
	// This function hooks the function to the event so it can trigger. Functinos can be dynamically hooked and unhooked.
	//void MyEventHook(ACharacterController* pSource); will need to check into this again at rebuild of Character and Input management. 
	//void MyEventUnHook(ACharacterController* pSource); currently it would cause circular reference to have the controller here

};
