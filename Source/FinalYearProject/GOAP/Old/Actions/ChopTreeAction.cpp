// Fill out your copyright notice in the Description page of Project Settings.

#include "ChopTreeAction.h"
#include "Kismet/GameplayStatics.h"
#include "../ChoppingBlock.h"

UChopTreeAction::UChopTreeAction()
{
	AddPrecondition("HasTool", true); //Requires a tool to perform action
	AddPrecondition("HasFirewood", false); //If already have firewood, dont need more firewood
	AddEffect("HasFirewood", true);
	AddEffect("HasTool", false);
}

void UChopTreeAction::Reset()
{
	bChopped = false;
	ChoppingBlock = nullptr;
	Progress = 0.0f;
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
	return SetDestinationActorToTargetClass(Agent, AChoppingBlock::StaticClass());
}

bool UChopTreeAction::Perform(AActor* Agent, float Deltatime)
{
	if (Progress < WorkDuration)
	{
		Progress += Deltatime;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Agent Chopping Wood")));
	}
	else
	{
		//Action Complete
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Agent Finished Chopping Wood")));
		bChopped = true;
	}

	return true;
}