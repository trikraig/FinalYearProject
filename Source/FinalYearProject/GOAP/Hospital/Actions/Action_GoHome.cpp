// Fill out your copyright notice in the Description page of Project Settings.


#include "Action_GoHome.h"

UAction_GoHome::UAction_GoHome()
{
	AddPreconditions();
	AddEffects();
}

void UAction_GoHome::AddPreconditions()
{
	//AddPrecondition(TEXT("BeCured"), true);
}

void UAction_GoHome::AddEffects()
{
	AddEffect(TEXT("BeHome"), true);
}

bool UAction_GoHome::RequiresInRange()
{
	return true;
}

bool UAction_GoHome::CheckProceduralPrecondition(AActor* Agent)
{
	return SetDestinationActorToTargetWithTag(Agent, FName("Home"));
}

bool UAction_GoHome::Perform(AActor* Agent, float Deltatime)
{
	//Agent has made it home, set task to completed.
	bIsDone = true;
	return bIsDone;
}
