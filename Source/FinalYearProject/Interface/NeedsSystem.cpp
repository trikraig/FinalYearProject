// Fill out your copyright notice in the Description page of Project Settings.

#include "NeedsSystem.h"

// Sets default values for this component's properties
UNeedsSystem::UNeedsSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Populate Needs

	FNeed NewNeed;
	NewNeed.Name = TEXT("Energy");
	NewNeed.Type = ENERGY;
	Needs.Add(NewNeed);
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
	for (int i = 0; i < Needs.Num(); i++)
	{
		Tick_Goal(DeltaTime, Needs[i]);
	}
}

void UNeedsSystem::Tick_Goal(float DeltaTime, FNeed& Goal)
{
	//Increase goal value by delta time and clamp at max value.
	Goal.Value = FMath::Clamp((Goal.Value += DeltaTime), 0.0f, 100.0f);

	//Check if should be action?
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Goal: %s, Value: %f"), *Goal.Name, Goal.Value));

	
}

float FNeed::GetDiscontentment(float NewValue) const
{
	return NewValue * NewValue; //????
}
