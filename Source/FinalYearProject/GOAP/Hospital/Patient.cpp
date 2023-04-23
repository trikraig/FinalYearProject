// Fill out your copyright notice in the Description page of Project Settings.


#include "Patient.h"
#include "Actions/Action_GoToActorWithTag.h"
#include "Actions/Action_GoToWaitingRoom.h"
#include "Actions/Action_GetTreated.h"
#include "../WorldStateSubSystem.h"


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
	GoToHospitalAction->AddPrecondition(TEXT("AtHospital"), false);
	GoToHospitalAction->AddEffect(TEXT("AtHospital"), true);
	GoToHospitalAction->ActionName = FText::FromString("Go To Hospital");
	Planner->AvailableActions.Add(GoToHospitalAction);

	//Register At Reception.
	auto RegisterAtReception = NewObject<UAction_GoToActorWithTag>();
	RegisterAtReception->TagName = "Reception";
	RegisterAtReception->ActionName = FText::FromString("Register At Reception");
	RegisterAtReception->AddPrecondition(TEXT("AtHospital"), true);
	RegisterAtReception->AddPrecondition(TEXT("HasRegistered"), false);
	RegisterAtReception->AddEffect(TEXT("HasRegistered"), true);
	Planner->AvailableActions.Add(RegisterAtReception);

	//Wait in Waiting Area - WaitingArea
	auto GoToWaitingArea = NewObject<UAction_GoToWaitingRoom>();
	GoToWaitingArea->TagName = "WaitingArea";
	GoToWaitingArea->ActionName = FText::FromString("Wait in Waiting Area");
	GoToWaitingArea->AddPrecondition(TEXT("HasRegistered"), true);
	GoToWaitingArea->AddPrecondition(TEXT("WaitingForTreatment"), false);

	GoToWaitingArea->AddEffect(TEXT("WaitingForTreatment"), true);
	Planner->AvailableActions.Add(GoToWaitingArea);

	//Get Treated Action.
	auto GetTreated = NewObject<UAction_GetTreated>();
	GetTreated->ActionName = FText::FromString("Get Treatment");
	GetTreated->AddPrecondition(TEXT("WaitingForTreatment"), true);
	GetTreated->AddEffect(TEXT("BeCured"), true);
	Planner->AvailableActions.Add(GetTreated);


	//Go Home Action
	auto GoHomeAction = NewObject<UAction_GoToActorWithTag>();
	GoHomeAction->TagName = "Home";
	GoHomeAction->ActionName = FText::FromString("Go Home");
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
}

void APatient::SetInitialState()
{
	Super::SetInitialState();

	//reverse of goals, could be set programatically...
	Planner->AddState(TEXT("BeCured"), false);
	Planner->AddState(TEXT("BeHome"), false);
	Planner->AddState(TEXT("AtHospital"), false);
	Planner->AddState(TEXT("HasRegistered"), false);
	Planner->AddState(TEXT("WaitingForTreatment"), false);


}

void APatient::SendToBeCured(AActor* Cubicle)
{
	Inventory->AddItem(Cubicle);
	Planner->RemoveGoal(TEXT("WaitingForTreatment"));
	Planner->AddGoal(TEXT("BeHome"), true);
}

void APatient::PopulateUIWithPlan(const FText& ActionName)
{
	//Plan Generated.
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	check(GameInstance);

	UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
	check(WorldStateSubSystem);

	if (WorldStateSubSystem->PlanUI)
	{
		WorldStateSubSystem->PlanUI->AddPlanItem(ActionName);
	}
}

void APatient::ClearPlanUI()
{
	//Plan Generated.
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	check(GameInstance);

	UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
	check(WorldStateSubSystem);

	if (WorldStateSubSystem->PlanUI)
	{
		WorldStateSubSystem->PlanUI->ClearPlanItems();
	}
}

