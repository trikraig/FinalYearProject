// Fill out your copyright notice in the Description page of Project Settings.


#include "Patient.h"
#include "Actions/Action_GoToActorWithTag.h"


void APatient::AddAvailableActions()
{
	Super::AddAvailableActions();

	/*Actions to Add
	* Go To Hospital
	* Register
	* Get Treated
	* Go Home
	*/

	//Go To Hospital
	auto GoToHospitalAction = NewObject<UAction_GoToActorWithTag>();
	GoToHospitalAction->TagName = "Entrance";
	GoToHospitalAction->AddPrecondition(TEXT("BeCured"), false);
	GoToHospitalAction->AddEffect(TEXT("AtHospital"), true);
	Planner->AvailableActions.Add(GoToHospitalAction);

	//Register At Reception.
	auto RegisterAtReception = NewObject<UAction_GoToActorWithTag>();
	RegisterAtReception->TagName = "Reception";
	RegisterAtReception->AddPrecondition(TEXT("AtHospital"), true);
	RegisterAtReception->AddEffect(TEXT("HasRegistered"), true);
	Planner->AvailableActions.Add(RegisterAtReception);

	//Wait in Waiting Area - WaitingArea
	auto GoToWaitingArea = NewObject<UAction_GoToActorWithTag>();
	GoToWaitingArea->TagName = "WaitingArea";
	GoToWaitingArea->AddPrecondition(TEXT("AtHospital"), true);
	GoToWaitingArea->AddPrecondition(TEXT("HasRegistered"), true);
	GoToWaitingArea->AddWorldEffect(TEXT("WaitingForTreatment"), true);
	Planner->AvailableActions.Add(GoToWaitingArea);

	//Go Home Action
	auto GoHomeAction = NewObject<UAction_GoToActorWithTag>();
	GoHomeAction->TagName = "Home";
	GoHomeAction->AddPrecondition(TEXT("BeCured"), true);
	GoHomeAction->AddEffect(TEXT("BeHome"), true);
	Planner->AvailableActions.Add(GoHomeAction);
	

}

void APatient::AddGoals()
{
	Super::AddGoals();

	/*Goals
	* 
	* Goal of any patient. Be healthy and Be Home
	* However, first goal should only be to get cured. 
	* Only then will goal be able to Go Home. 
	* Curing taken care of by nurse, so only thing patient can do in their power is get themselves to hospital and be registed for treatment.
	*/

	
	Planner->AddGoal(TEXT("WaitingForTreatment"), true);
//	Planner->AddGoal(TEXT("BeHome"), true);
}

void APatient::SetInitialState()
{
	Super::SetInitialState();

	//reverse of goals, could be set programatically...
	Planner->AddState(TEXT("BeCured"), false);
	Planner->AddState(TEXT("BeHome"), false);
	Planner->AddState(TEXT("AtHospital"), false);
	Planner->AddState(TEXT("HasRegistered"), false);

}
