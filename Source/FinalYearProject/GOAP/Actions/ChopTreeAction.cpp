// Fill out your copyright notice in the Description page of Project Settings.


#include "ChopTreeAction.h"
#include "Kismet/GameplayStatics.h"

UChopTreeAction::UChopTreeAction()
{
	AddPrecondition("HasTool", true); //Requires a tool to perform action
	AddPrecondition("HasFirewood", false); //If already have firewood, dont need more firewood
	AddEffect("HasFirewood", true);
}

void UChopTreeAction::Reset()
{
	bChopped = false;
	ChoppingBlock = nullptr;
	StartTimer = 0.0f;
}

bool UChopTreeAction::IsDone()
{
	return bChopped;
}

bool UChopTreeAction::RequiresInRange()
{
	return true; // need to be in range of chopping block.
}

bool UChopTreeAction::CheckProceduralPrecondition(AActor* Agent)
{
	TArray<AActor*> FoundStations;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ChoppingBlockClass, FoundStations);

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


	ChoppingBlock = Closest;
	TargetObject = Closest;
	return true;
}

bool UChopTreeAction::Perform(AActor* Agent)
{
	//TODO - Action

	/*

			if (startTime == 0)
			startTime = Time.time;

		if (Time.time - startTime > workDuration) {
			// finished chopping
			BackpackComponent backpack = (BackpackComponent)agent.GetComponent(typeof(BackpackComponent));
			backpack.numFirewood += 5;
			chopped = true;
			ToolComponent tool = backpack.tool.GetComponent(typeof(ToolComponent)) as ToolComponent;
			tool.use(0.34f);
			if (tool.destroyed()) {
				Destroy(backpack.tool);
				backpack.tool = null;
			}
		}

	*/

	return true;
}

