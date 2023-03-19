// Fill out your copyright notice in the Description page of Project Settings.


#include "GoapAction.h"

void UGoapAction::DoReset()
{
	bInRange = false;
	TargetObject = nullptr;
	Reset();
}

void UGoapAction::Reset()
{

}

bool UGoapAction::IsDone()
{
	return true;
}

bool UGoapAction::CheckProceduralPrecondition(AActor* Agent)
{
	return Agent != nullptr;
}

bool UGoapAction::Perform(AActor* Agent)
{
	return Agent != nullptr;
}

bool UGoapAction::RequiresInRange()
{
	return false; //Default - don't need to be near object
}

void UGoapAction::AddPrecondition(FString Key, bool bValue)
{
	Preconditions.Add(Key, bValue);
}

void UGoapAction::RemovePrecondition(FString Key)
{
	Preconditions.Remove(Key);
}

void UGoapAction::AddEffect(FString Key, bool bValue)
{
	Effects.Add(Key, bValue);
}

void UGoapAction::RemoveEffect(FString Key)
{
	Effects.Remove(Key);
}

TMap<FString, bool> UGoapAction::GetConditions()
{
	return Preconditions;
}

TMap<FString, bool> UGoapAction::GetEffects()
{
	return Effects;
}