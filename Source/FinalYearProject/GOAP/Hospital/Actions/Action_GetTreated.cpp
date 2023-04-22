// Fill out your copyright notice in the Description page of Project Settings.


#include "Action_GetTreated.h"
#include "../../GoapAgent.h"

bool UAction_GetTreated::CheckProceduralPrecondition(AActor* Actor)
{
	//Get cubicle from inventory.
	AActor* Cubicle = nullptr;
	if (AGoapAgent* Agent = Cast<AGoapAgent>(Actor))
	{
		Cubicle = Agent->Inventory->FindItemWithTag(TEXT("Cubicle"));
	}

	if (Cubicle)
	{
		TargetObject = Cubicle;
	}

	return TargetObject != nullptr;
}

bool UAction_GetTreated::RequiresInRange()
{
	return true;
}
