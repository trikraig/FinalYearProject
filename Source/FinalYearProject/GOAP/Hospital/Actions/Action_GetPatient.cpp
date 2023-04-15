// Fill out your copyright notice in the Description page of Project Settings.


#include "Action_GetPatient.h"
#include "../../WorldStateSubSystem.h"

bool UAction_GetPatient::CheckProceduralPrecondition(AActor* Agent)
{
	//TargetObject to be Patient from Queue in World State.

	UGameInstance* GameInstance = Agent->GetWorld()->GetGameInstance();
	check(GameInstance);

	UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
	check(WorldStateSubSystem);

	APatient* Patient = nullptr;
	WorldStateSubSystem->WaitingPatients.Peek(Patient);
	if (Patient)
	{
		TargetObject = Patient;
		WorldStateSubSystem->WaitingPatients.Pop();
		WorldStateSubSystem->TotalWaitingPatients--;
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
}
