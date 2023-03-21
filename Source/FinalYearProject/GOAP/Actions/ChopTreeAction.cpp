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
	//return SetDestinationActorToTargetClass(Agent, ChoppingBlockClass);

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