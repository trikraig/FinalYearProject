// Fill out your copyright notice in the Description page of Project Settings.


#include "Nurse.h"

void ANurse::AddAvailableActions()
{
	Super::AddAvailableActions();

}

void ANurse::AddGoals()
{
	Super::AddGoals();

	Planner->AddGoal(TEXT("TreatPatient"), true);

}

void ANurse::SetInitialState()
{
	Super::SetInitialState();

}
