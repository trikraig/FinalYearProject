// Fill out your copyright notice in the Description page of Project Settings.

#include "GiveToolAction.h"
#include "Kismet/GameplayStatics.h"


UGiveToolAction::UGiveToolAction()
{
	AddEffect("HasTool", true);
}

void UGiveToolAction::Reset()
{
	bGivenTool = false;
}

bool UGiveToolAction::IsDone()
{
	return bGivenTool;
}

bool UGiveToolAction::RequiresInRange()
{
	return true; // need to be in range of the tool
}

bool UGiveToolAction::CheckProceduralPrecondition(AActor* Agent)
{
	TArray<AActor*> FoundStations;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ToolClass, FoundStations);

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

	Tool = Closest;
	TargetObject = Closest;
	return true;
}

bool UGiveToolAction::Perform(AActor* Agent)
{
	static bool bResult = false;

	return bResult;
}
