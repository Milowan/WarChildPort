
#include "CharacterController.h"

ACharacterController::ACharacterController()
{
	movSpeed = 100;
	jumping = false;
	jumpSpeed = 10;
	maxPitch = 30;
	sensitivity = 5;
	pitch = 0;
	yaw = 0;

	//If you're looking for players, why not just search for the player characters?
	TSubclassOf<AActor> classToFind;//Not necessary
	TArray<AActor*> foundPlayerArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), foundPlayerArray);
	if (foundPlayerArray[0])
	{
		player = Cast<APlayerCharacter>(foundPlayerArray[0]);//Lets check pointers before we try to access them.
		
		if(player)
			playerCamera = player->GetFollowCamera();
	}	
}

ACharacterController::~ACharacterController()
{
}

void ACharacterController::BeginPlay()
{
	Super::BeginPlay(); //Otherwise your tick wont run... Should keep in the habit of calling parent functions when dealing with engine related functions.

	//I dont know why this line gets mad but we cant hook into the overlap events without it.
	//player->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::BeginOverlap);
}

void ACharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!player || !playerCamera)//fail safe
		return;

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

void ACharacterController::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	int tempTerrain = 0; // to become Terrain tempTerrain = Cast<Terrain>(OtherActor);
	if (tempTerrain)
	{
		jumping = false;
	}
}
