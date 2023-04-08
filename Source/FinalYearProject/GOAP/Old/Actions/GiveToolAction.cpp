// Fill out your copyright notice in the Description page of Project Settings.

#include "GiveToolAction.h"
#include "Kismet/GameplayStatics.h"
#include "../Tool.h"

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
	//Finds closest tool and sets as destination.
	return SetDestinationActorToTargetClass(Agent, ATool::StaticClass());
}

bool UGiveToolAction::Perform(AActor* Agent, float Deltatime)
{
	//Give Tool To Agent 
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Agent Given Tool.")));

	bGivenTool = true;

	return bGivenTool;
}
