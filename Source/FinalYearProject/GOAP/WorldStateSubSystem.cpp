// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldStateSubSystem.h"

UWorldStateSubSystem::UWorldStateSubSystem()
{
}

TMap<FString, bool> UWorldStateSubSystem::GetWorldState()
{
	return WorldState;
}

void UWorldStateSubSystem::AddState(const FString& NewState, bool bSetting)
{
	WorldState.FindOrAdd(NewState, bSetting);
}

void UWorldStateSubSystem::RemoveState(const FString& State)
{
	WorldState.Remove(State);
}