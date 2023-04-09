// Fill out your copyright notice in the Description page of Project Settings.


#include "Action_GoToActorWithTag.h"

UAction_GoToActorWithTag::UAction_GoToActorWithTag()
{
}

bool UAction_GoToActorWithTag::RequiresInRange()
{
	//Need to be in range of actor.
	return true;
}

bool UAction_GoToActorWithTag::CheckProceduralPrecondition(AActor* Agent)
{
	//Check if actor exists in level with Tag, and if true will set as Target Actor.
	return SetDestinationActorToTargetWithTag(Agent, TagName);
}

bool UAction_GoToActorWithTag::Perform(AActor* Agent, float Deltatime)
{
	//Agent has made it target actor, mark as completed.
	bIsDone = true;
	return bIsDone;
}
