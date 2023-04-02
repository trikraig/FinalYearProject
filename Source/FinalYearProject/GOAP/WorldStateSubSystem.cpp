// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldStateSubSystem.h"

UWorldStateSubSystem::UWorldStateSubSystem()
{

}

void UWorldStateSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	//Resulting from ChopTreeAction. Starting point with one action 
	AddGoal(TEXT("HasFire"), true);
	//Currently 
	AddState("HasFire", false);
	AddState("HasFirewood", false);
	AddState("HasTool", false); //likely need to override world state with current state of agent, e.g. has tool.
}

TMap<FString, bool> UWorldStateSubSystem::GetWorldState()
{
	return WorldState;
}

TMap<FString, bool> UWorldStateSubSystem::GetGoalState()
{
	return GoalState;
}

void UWorldStateSubSystem::AddState(const FString& NewState, bool bSetting)
{
	WorldState.FindOrAdd(NewState, bSetting);
}

void UWorldStateSubSystem::RemoveState(const FString& State)
{
	WorldState.Remove(State);
}

void UWorldStateSubSystem::AddGoal(const FString& NewGoal, bool bSetting)
{
	GoalState.FindOrAdd(NewGoal, bSetting);
}

void UWorldStateSubSystem::RemoveGoal(const FString& Goal)
{
	GoalState.Remove(Goal);
}
