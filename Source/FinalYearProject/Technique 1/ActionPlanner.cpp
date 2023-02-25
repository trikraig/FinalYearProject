// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionPlanner.h"
#include "../Interface/NeedsSystem.h"

// Sets default values for this component's properties
UActionPlanner::UActionPlanner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActionPlanner::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActionPlanner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FAction* UActionPlanner::ChooseAction(const TArray<FNeed>& Needs)
{
	//Find action with lowest discontentment

	FAction* pBestAction = nullptr;
	float	 fBestValue = FLT_MAX;

	//for (auto& Action : Actions)
	//{
	//	float ActionValue = Discontentment(Action, Needs);
	//	if (ActionValue < fBestValue)
	//	{
	//		fBestValue = ActionValue;
	//		pBestAction = Action;
	//	}
	//}

	return pBestAction;
}

float UActionPlanner::Discontentment(const FAction& Action, const TArray<FNeed>& Needs) const
{
	//Keep running total
	float fDiscontentment = 0.0f;

	//Loop through each goal
	for (auto& Need : Needs)
	{
		//Calculate new value after the action
		float fNewValue = Need.Value + Action.GetNeedChange(Need);

		//Get the discontentment of this value.
		fDiscontentment += Need.GetDiscontentment(fNewValue);
	}

	return fDiscontentment;
}

float FAction::GetNeedChange(const FNeed& Need) const
{
	//Check if fulfills need
	if (Need.Type == Type)
	{
		//Return Need Change
		return Need.Value - Value;
	}

	return 0.0f;
}
