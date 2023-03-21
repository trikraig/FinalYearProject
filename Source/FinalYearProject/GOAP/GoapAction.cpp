// Fill out your copyright notice in the Description page of Project Settings.


#include "GoapAction.h"
#include "Kismet/GameplayStatics.h"

void UGoapAction::DoReset()
{
	bInRange = false;
	TargetObject = nullptr;
	Reset();
}

void UGoapAction::Reset()
{

}

bool UGoapAction::IsDone()
{
	return true;
}

bool UGoapAction::CheckProceduralPrecondition(AActor* Agent)
{
	return Agent != nullptr;
}

bool UGoapAction::Perform(AActor* Agent)
{
	return Agent != nullptr;
}

bool UGoapAction::RequiresInRange()
{
	return false; //Default - don't need to be near object
}

bool UGoapAction::IsInRange(AActor* Agent) const
{
	return (TargetObject->GetActorLocation() - Agent->GetActorLocation()).Length() < Range;
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
	TArray<AActor*> FoundStations;
	UGameplayStatics::GetAllActorsOfClass(Agent->GetWorld(), TargetClass, FoundStations);

	AActor* Closest = nullptr;
	float ClosestDist = FLT_MAX;

	for (auto Station : FoundStations)
	{
		if (!Closest)
		{
			Closest = Station;
			ClosestDist = (Agent->GetActorLocation() - Station->GetActorLocation()).SquaredLength();
		}
		else
		{
			float Distance = (Agent->GetActorLocation() - Station->GetActorLocation()).SquaredLength();

			if (Distance < ClosestDist)
			{
				//Set as closest
				Closest = Station;
				ClosestDist = Distance;
			}
		}
	}

	//If didn't find a station return false.
	if (Closest == nullptr) return false;

	TargetObject = Closest;
	return true;
}
