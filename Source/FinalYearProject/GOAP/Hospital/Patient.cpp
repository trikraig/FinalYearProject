// Fill out your copyright notice in the Description page of Project Settings.


#include "Patient.h"
#include "Actions/Action_GoHome.h"

void APatient::AddAvailableActions()
{
	Super::AddAvailableActions();

	/*Actions to Add
	* Go To Hospital
	* Register
	* Get Treated
	* Go Home
	*/

	Planner->AvailableActions.Add(NewObject<UAction_GoHome>());
}

void APatient::AddGoals()
{
	Super::AddGoals();

	/*Goals
	* 
	* Goal of any patient. Be healthy and Be Home
	*/

	//Planner->AddGoal(TEXT("BeCured"), true);
	Planner->AddGoal(TEXT("BeHome"), true);
}

void APatient::SetInitialState()
{
	Super::SetInitialState();

	//reverse of goals, could be set programatically...
	Planner->AddState(TEXT("BeCured"), false);
	Planner->AddState(TEXT("BeHome"), false);

}
