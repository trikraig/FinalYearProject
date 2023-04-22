// Fill out your copyright notice in the Description page of Project Settings.


#include "Nurse.h"
#include "Actions/Action_GetPatient.h"
#include "Actions/Action_GetTreated.h"

void ANurse::AddAvailableActions()
{
	Super::AddAvailableActions();

	auto GetPatientAction = NewObject<UAction_GetPatient>();
	GetPatientAction->AddEffect(TEXT("GetPatient"), true);
	Planner->AvailableActions.Add(GetPatientAction);

	//Get Treated Action.
	auto GetTreated = NewObject<UAction_GetTreated>();
	GetTreated->AddPrecondition(TEXT("GetPatient"), true);
	GetTreated->AddEffect(TEXT("CuredPatient"), true);
	Planner->AvailableActions.Add(GetTreated);
}

void ANurse::AddGoals()
{
	Super::AddGoals();

	Planner->AddGoal(TEXT("CuredPatient"), true);

}

void ANurse::SetInitialState()
{
	Super::SetInitialState();

}
