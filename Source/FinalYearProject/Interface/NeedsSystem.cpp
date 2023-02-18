// Fill out your copyright notice in the Description page of Project Settings.

#include "NeedsSystem.h"

// Sets default values for this component's properties
UNeedsSystem::UNeedsSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Populate Needs
	UGoal* NewGoal = NewObject<UGoal>(UGoal::StaticClass());
	Needs.Add(NewGoal);

}

UNeedsSystem::~UNeedsSystem()
{
	//for (int i = 0; i < Needs.Num(); i++)
	//{
	//	UGoal* Need = Needs[i];

	//	delete Need;
	//}
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
		UGoal* Need = Needs[i];

		Tick_Goal(DeltaTime, Need);
	}
}

void UNeedsSystem::Tick_Goal(float DeltaTime, UGoal* Goal)
{
	//Increase goal value by delta time and clamp at max value.
	Goal->Value = FMath::Clamp(Goal->Value += DeltaTime, 0.0f, 1.0f);

	//Check if should be action?
}

