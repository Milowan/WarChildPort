// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Characters/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "CharacterController.generated.h"

/**
 *
 */

/*Steven
* 
* Not sure what - [event_source(native)]  - is supposed to do, but you need to use delegates when making events.
* https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Delegates/index.html
* https://wiki.unrealengine.com/Delegates_In_UE4,_Raw_Cpp_and_BP_Exposed

-- To declare events, you have access to the following calls--
DECLARE_DYNAMIC_MULTICAST_DELEGATE		-- No parameters
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams


Now, each one of these specify how many parameters you want the functions binding to the event need. OneParam = 1 Parameter, TwoParams= 2 Parameters

Now here is an actual example to define your events, just add/remove in extra params in which you specify
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FNameSignature,			class AActor*,				OtherActor)
												  Key					  Data Type				   Variable Name 
									_____________^
									^- F(Name)Signature is convention - Just change Name to something meaningful
									
									NOTE: Don't think of this as a function call where you can do something like the following
									DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNameSignature, Class AActor* OtherActor) - THIS WILL NOT WORK!! you need to add a comma between the Data type and the variable name


-------End of Declare-------


---Goes in UCLASS header---
UPROPERTY()
FNameSignature OnHit;


---Goes in UCLASS source---
OnHit.Broadcast() - Broadcast everyone listing to the onHit event

---Goes in UCLASS source that needs to listen to the Hit Event---
---Add to source code when you want to bind the onHit Event to a function call.---
ClassThatHoldsTheOnHitEvent->OnHit.AddDynamic(this, &USomeClass::RespondToMeleeDamageTaken);			- Binds the event
ClassThatHoldsTheOnHitEvent->OnHit.RemoveDynamic(this, &USomeClass::RespondToMeleeDamageTaken);			- Unbinds the event

*/
//[event_source(native)] 
UCLASS()
class WARCHILD_API ACharacterController : public AActor
{

	GENERATED_BODY()

private:
	float movSpeed;
	float sensitivity;
	float pitch;
	float maxPitch;
	float yaw;
	float jumpSpeed;
	bool jumping;

	UCameraComponent* playerCamera;
	APlayerCharacter* player;


public:
	ACharacterController ();
	~ACharacterController();

	// Called every frame
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult &SweepResult);

	//__event void MyEvent(int nValue);


protected:


};