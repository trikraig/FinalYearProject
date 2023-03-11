// Fill out your copyright notice in the Description page of Project Settings.

#include "NeedsSystem.h"

// Sets default values for this component's properties
UNeedsSystem::UNeedsSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Populate Needs
	for (ENeedType NeedType : TEnumRange<ENeedType>())
	{
		FNeed NewNeed;
		NewNeed.Name = "NEED NAME"; //TODO ADD GET NAME FUNCTION VIA
		NewNeed.Type = NeedType;
		NeedsMap.Add(NeedType, NewNeed);
	}
}

// Called when the game starts
void UNeedsSystem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UNeedsSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Tick Needs
	for (auto& Need : NeedsMap)
	{
		Tick_Need(DeltaTime, Need.Value);
	}
 
}

void UNeedsSystem::Tick_Need(float DeltaTime, FNeed& Need)
{
	//Increase goal value by delta time and clamp at max value.
	Need.Value = FMath::Clamp((Need.Value += DeltaTime), 0.0f, 100.0f);

	//Check if should be action?
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Goal: %s, Value: %f"), *Goal.Name, Goal.Value));

	
}

void UNeedsSystem::FufillNeed(const ENeedType& NeedType, float Amount)
{
	//check if need in needs map
	bool bHasNeed = NeedsMap.Contains(NeedType);

	//if found, reduce need value by amount;
	if (bHasNeed)
	{
		auto& Need = NeedsMap[NeedType];
		Need.Value -= Amount;
	}
}

