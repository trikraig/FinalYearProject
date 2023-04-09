// Fill out your copyright notice in the Description page of Project Settings.

#include "Action_EscortActorToTarget.h"
#include "Kismet/GameplayStatics.h"


UAction_EscortActorToTarget::UAction_EscortActorToTarget()
{
}

bool UAction_EscortActorToTarget::RequiresInRange()
{
	// Will handle movement in this class.
	return false;
}

bool UAction_EscortActorToTarget::CheckProceduralPrecondition(AActor* ParentActor)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(ParentActor->GetWorld(), TargetClass, FoundActors);

	float ClosestDist = FLT_MAX;

	for (auto Actor : FoundActors)
	{
		AGoapAgent* Agent = Cast<AGoapAgent>(Actor);
		check(Agent);

		//Check if Agent in valid state. e.g. waiting to be healed.
		bool bValidState = Agent->Planner->InState(TargetActorConditionKey, bTargetActorConditionValue);
		if (!bValidState) continue;

		//If no escorted agent, set as closest else check distance.
		if (!EscortedAgent)
		{
			EscortedAgent = Agent;
			ClosestDist = (Agent->GetActorLocation() - Actor->GetActorLocation()).SquaredLength();
		}
		else
		{
			float Distance = (Agent->GetActorLocation() - Actor->GetActorLocation()).SquaredLength();

			if (Distance < ClosestDist)
			{
				//Set as closest
				EscortedAgent = Agent;
				ClosestDist = Distance;
			}
		}
	}

	//Valid when we have an actor to escort, and a valid destination.
	return EscortedAgent != nullptr && SetDestinationActorToTargetWithTag(ParentActor, TagName);
}

bool UAction_EscortActorToTarget::Perform(AActor* Agent, float Deltatime)
{
	//First need to check if actor to escort is currently attached to me.

	//If it is can walk towards target,

	//else walk towards actor to escort.

	return false;
}

