// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldStateSubSystem.h"
#include "Kismet/GameplayStatics.h"

UWorldStateSubSystem::UWorldStateSubSystem()
{
}

void UWorldStateSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Cubicle", FoundActors);

	for (AActor* Actor : FoundActors)
	{
		Cubicles.Enqueue(Actor);
	}

	if (!Cubicles.IsEmpty())
	{
		AddState("FreeCubicles", true);
	}
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

