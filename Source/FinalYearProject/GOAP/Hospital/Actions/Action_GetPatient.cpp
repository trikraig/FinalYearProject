// Fill out your copyright notice in the Description page of Project Settings.


#include "Action_GetPatient.h"
#include "../../WorldStateSubSystem.h"
#include "../../GoapAgent.h"
#include "../Patient.h"

bool UAction_GetPatient::CheckProceduralPrecondition(AActor* Actor)
{
	//TargetObject to be Patient from Queue in World State.

	UGameInstance* GameInstance = Actor->GetWorld()->GetGameInstance();
	check(GameInstance);

	UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
	check(WorldStateSubSystem);

	APatient* Patient = nullptr;
	WorldStateSubSystem->Patients.Peek(Patient);
	if (Patient)
	{
		TargetObject = Patient;
		WorldStateSubSystem->Patients.Pop();
	}

	//If we've found a patient, now we need a cubicle to heal them in.
	if (Patient)
	{
		AActor* Cubicle = nullptr;
		WorldStateSubSystem->Cubicles.Peek(Cubicle);
		if (Cubicle)
		{
			//Add to agent inventory.
			if (AGoapAgent* Agent = Cast<AGoapAgent>(Actor))
			{
				Agent->Inventory->AddItem(Cubicle);
				WorldStateSubSystem->Cubicles.Pop();
			}
		}
		else //If failed to find cubicle, undo the patient capturing and restore to world state.
		{
			WorldStateSubSystem->Patients.Enqueue(Patient);
			Patient = nullptr;
			TargetObject = nullptr;
		}
	}

	return Patient != nullptr;
}

bool UAction_GetPatient::RequiresInRange()
{
	return true;
}

void UAction_GetPatient::PostPerform(AActor* Actor)
{
	Super::PostPerform(Actor);

	//Update total waiting patients in world.
	UGameInstance* GameInstance = Actor->GetWorld()->GetGameInstance();
	check(GameInstance);
	UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
	check(WorldStateSubSystem);
	WorldStateSubSystem->TotalWaitingPatients--;

	//Get cubicle from inventory.
	AActor* Cubicle = nullptr;
	if (AGoapAgent* Agent = Cast<AGoapAgent>(Actor))
	{
		Cubicle = Agent->Inventory->FindItemWithTag(TEXT("Cubicle"));
	}

	//Should of found a cubicle, error if not.
	check(Cubicle);

	//Need to Give cubicle to the patient so know where to go.
	if (TargetObject)
	{
		if (APatient* Patient = Cast<APatient>(TargetObject))
		{
			Patient->SendToBeCured(Cubicle);
		}
	}

}
