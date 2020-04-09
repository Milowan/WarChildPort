// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Stats/CharacterStats/CharacterStats.h"
#include "WarchildGameState.h"
#include "BaseCharacter.generated.h"

UCLASS(abstract)
class WARCHILD_API ABaseCharacter : public ACharacter
{
private:

	GENERATED_BODY()

	FVector spawnPoint;

protected:

	bool active;
	CharacterStats* stats;

public:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

private:

	void Pause();
	void UnPause();


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetStats() PURE_VIRTUAL(ABaseCharacter::SetStats, ;);

public:	

	// Sets default values for this character's properties
	ABaseCharacter(const FObjectInitializer& ObjectInitializer);

	~ABaseCharacter();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	void Damaged(float amount);
	virtual void Die() PURE_VIRTUAL(ABaseCharacter::Die, ;);

	void SetSpawnPoint(FVector);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	CharacterStats* GetStats();
	float GetHealthFraction();
};
