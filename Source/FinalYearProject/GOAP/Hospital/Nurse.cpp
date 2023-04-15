// Fill out your copyright notice in the Description page of Project Settings.


#include "Nurse.h"
#include "Actions/Action_GetPatient.h"

void ANurse::AddAvailableActions()
{
	Super::AddAvailableActions();

	auto GetPatientAction = NewObject<UAction_GetPatient>();
	GetPatientAction->AddEffect(TEXT("GetPatient"), true);
	Planner->AvailableActions.Add(GetPatientAction);
}

void ANurse::AddGoals()
{
	Super::AddGoals();

	Planner->AddGoal(TEXT("GetPatient"), true);

}

void ANurse::SetInitialState()
{
	Super::SetInitialState();

}
