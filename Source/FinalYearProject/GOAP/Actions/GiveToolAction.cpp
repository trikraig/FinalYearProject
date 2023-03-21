// Fill out your copyright notice in the Description page of Project Settings.

#include "GiveToolAction.h"
#include "Kismet/GameplayStatics.h"


UGiveToolAction::UGiveToolAction()
{
	AddPrecondition("HasTool", false); //Requires a tool to perform action
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
	//return SetDestinationActorToTargetClass(Agent, ChoppingBlockClass);

	return true;
}

bool UGiveToolAction::Perform(AActor* Agent)
{
	static bool bResult = false;

	return bResult;
}
