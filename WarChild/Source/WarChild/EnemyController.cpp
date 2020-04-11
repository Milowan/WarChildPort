// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"

AEnemyController::AEnemyController()
{
	rangeMax = 2000.0f;
	FoV = 110.0f;
	sightRange = 1000.0f;
	scanCD = 3.0f;
	scanTimer = scanCD;
	target = NULL;
}

void AEnemyController::OnMoveCompleted(FAIRequestID request, const FPathFollowingResult& result)
{
	if (GetState() == EnemyState::WANDERING)
	{
		SetRandomDestination();
	}
	else if (GetState() == EnemyState::CHASING)
	{
		MoveToActor(target);
	}
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyController::Tick(float DeltaTime)
{
	if (GetPawn()->IsActorTickEnabled())
	{
		if (GetState() == EnemyState::NONE)
		{
			SetState(EnemyState::WANDERING);
			SetRandomDestination();
		}
		else
		{
			if (target == NULL)
			{
				if (scanTimer >= scanCD)
				{
					int checkCount = 5;
					float angle = -(FoV / 2.0f);
					for (int i = 0; i < checkCount; ++i)
					{
						FVector direction = FRotator(0.0f, angle, 0.0f).Vector();
						APawn* pawn = GetPawn();
						direction += pawn->GetActorForwardVector();
						FHitResult hit;
						FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
						GetWorld()->LineTraceSingleByObjectType(OUT hit, pawn->GetActorLocation(), pawn->GetActorLocation() + (direction * sightRange), FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn), TraceParams);

						AActor* aHit = hit.GetActor();

						if (aHit != NULL)
						{
							ABaseCharacter* cHit = Cast<ABaseCharacter>(aHit);

							if (cHit != NULL)
							{
								if (Cast<AEnemyCharacter>(cHit) == NULL)
								{
									target = cHit;
									SetState(EnemyState::CHASING);
									MoveToActor(target);
								}
							}
						}
						angle += (FoV / 2.0f);
					}
				}
				else
				{
					scanTimer += DeltaTime;
				}
			}
			else
			{
				AEnemyCharacter* character = Cast<AEnemyCharacter>(GetPawn());
				EnemyStats* stats = (EnemyStats*)(character->GetStats());
				if (FVector::Distance(GetPawn()->GetActorLocation(), target->GetActorLocation()) <= stats->GetRange())
				{
					character->PullTrigger();
				}
			}
		}
	}
	else
	{
		target = NULL;
	}
}

void AEnemyController::SetState(EnemyState nState)
{
	state = nState;
}

EnemyState AEnemyController::GetState()
{
	return state;
}

void AEnemyController::SetRangeMax(float value)
{
	rangeMax = value;
}

float AEnemyController::GetRangeMax()
{
	return rangeMax;
}