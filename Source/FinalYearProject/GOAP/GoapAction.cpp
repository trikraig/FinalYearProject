// Fill out your copyright notice in the Description page of Project Settings.


#include "GoapAction.h"
#include "Kismet/GameplayStatics.h"

UGoapAction::UGoapAction()
{
}

void UGoapAction::DoReset()
{
	bIsDone = false;
	bInRange = false;
	TargetObject = nullptr;
	Reset();
}

void UGoapAction::Reset()
{

}

bool UGoapAction::IsDone()
{
	return bIsDone;
}

bool UGoapAction::CheckProceduralPrecondition(AActor* Agent)
{
	return Agent != nullptr;
}

bool UGoapAction::Perform(AActor* Agent, float Deltatime)
{
	return Agent != nullptr;
}

bool UGoapAction::RequiresInRange()
{
	return false; //Default - don't need to be near object
}

bool UGoapAction::IsInRange(AActor* Agent) const
{
	float Distance = (TargetObject->GetActorLocation() - Agent->GetActorLocation()).Length();
	return Distance <= Range;
}

void UGoapAction::AddPrecondition(FString Key, bool bValue)
{
	Preconditions.Add(Key, bValue);
}

void UGoapAction::RemovePrecondition(FString Key)
{
	Preconditions.Remove(Key);
}

void UGoapAction::AddEffect(FString Key, bool bValue)
{
	Effects.Add(Key, bValue);
}

void UGoapAction::RemoveEffect(FString Key)
{
	Effects.Remove(Key);
}

TMap<FString, bool> UGoapAction::GetConditions()
{
	return Preconditions;
}

TMap<FString, bool> UGoapAction::GetEffects()
{
	return Effects;
}

bool UGoapAction::SetDestinationActorToTargetClass(AActor* Agent, TSubclassOf<AActor> TargetClass)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(Agent->GetWorld(), TargetClass, FoundActors);

	AActor* Closest = nullptr;
	float ClosestDist = FLT_MAX;

	for (auto Actor : FoundActors)
	{
		if (!Closest)
		{
			Closest = Actor;
			ClosestDist = (Agent->GetActorLocation() - Actor->GetActorLocation()).SquaredLength();
		}
		else
		{
			float Distance = (Agent->GetActorLocation() - Actor->GetActorLocation()).SquaredLength();

			if (Distance < ClosestDist)
			{
				//Set as closest
				Closest = Actor;
				ClosestDist = Distance;
			}
		}
	}

	//If didn't find a station return false.
	if (Closest == nullptr) return false;

	TargetObject = Closest;
	return true;
}

bool UGoapAction::SetDestinationActorToTargetWithTag(AActor* Agent, const FName& TagName)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(Agent->GetWorld(), TagName, FoundActors);

	AActor* Closest = nullptr;
	float ClosestDist = FLT_MAX;

	for (auto Actor : FoundActors)
	{
		if (!Closest)
		{
			Closest = Actor;
			ClosestDist = (Agent->GetActorLocation() - Actor->GetActorLocation()).SquaredLength();
		}
		else
		{
			float Distance = (Agent->GetActorLocation() - Actor->GetActorLocation()).SquaredLength();

			if (Distance < ClosestDist)
			{
				//Set as closest
				Closest = Actor;
				ClosestDist = Distance;
			}
		}
	}

	//If didn't find a station return false.
	if (Closest == nullptr) return false;

	TargetObject = Closest;
	return true;
}

