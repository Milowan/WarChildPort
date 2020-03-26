// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
#include "Kismet/GameplayStatics.h"

CharacterController::CharacterController()
{
	movSpeed = 100;
	jumping = false;
	jumpSpeed = 10;
	maxPitch = 30;
	sensitivity = 5;
	pitch = 0;
	yaw = 0;

	TSubclassOf<AActor> classToFind;
	TArray<AActor*> foundPlayerArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), classToFind, foundPlayerArray);
	player = Cast<APlayerCharacter>(foundPlayerArray[0]);
	playerCamera = player->GetFollowCamera();
}

CharacterController::~CharacterController()
{
}

void CharacterController::BeginPlay()
{
	//I dont know why this line gets mad but we cant hook into the overlap events without it.
	//player->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::BeginOverlap);
}

void CharacterController::Tick(float DeltaTime)
{
	FVector newPos(0.0f, 0.0f, 0.0f);
	//newPos.X = Horizontal input axis * movSpeed;   needs input manager hooked up
	newPos.Y = 0;
	//newPos.Z = Vetrical input axis * movSpeed;
	//yaw += MouseX input axis * sensitivity;
	//pitch -= MouseY input axis * (sensitivity / 2);
	if (pitch > maxPitch)
		pitch = maxPitch;
	if (pitch < -maxPitch)
		pitch = -maxPitch;
	FRotator newRot(0, 0, 0);
	newRot.Yaw = yaw;
	player->AddActorLocalRotation(newRot);
	//player->UpdateWeapon(pitch, yaw); ASK GAVIN ABOUT THIS FUNCTION
	newRot.Pitch = pitch;
	newRot.Yaw = 0;
	playerCamera->AddLocalRotation(newRot);
	// Call player->PullTrigger() if the LMB("Fire1") event fires.


}

void CharacterController::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	int tempTerrain = 0; // to become Terrain tempTerrain = Cast<Terrain>(OtherActor);
	if (tempTerrain)
	{
		jumping = false;
	}
}
