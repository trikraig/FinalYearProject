// Fill out your copyright notice in the Description page of Project Settings.


#include "Action_GetTreated.h"
#include "../../GoapAgent.h"
#include "../Nurse.h"
#include "../../WorldStateSubSystem.h"

bool UAction_GetTreated::CheckProceduralPrecondition(AActor* Actor)
{
	//Get cubicle from inventory.
	AActor* Cubicle = nullptr;
	if (AGoapAgent* Agent = Cast<AGoapAgent>(Actor))
	{
		Cubicle = Agent->Inventory->FindItemWithTag(TEXT("Cubicle"));
	}

	if (Cubicle)
	{
		TargetObject = Cubicle;
	}

	return TargetObject != nullptr;
}

bool UAction_GetTreated::RequiresInRange()
{
	return true;
}

void UAction_GetTreated::PostPerform(AActor* Actor)
{
	Super::PostPerform(Actor); 

	//Need to remove from player inventory.
	if (AGoapAgent* Agent = Cast<AGoapAgent>(Actor))
	{
		AActor* Cubicle = Agent->Inventory->FindItemWithTag(TEXT("Cubicle"));
		if (Cubicle)
		{
			Agent->Inventory->RemoveItem(Cubicle);
		}
		//If nurse, add back to world state
		if (ANurse* Nurse = Cast<ANurse>(Agent))
		{
			Nurse->ReadyForNextPatient();

			UGameInstance* GameInstance = Actor->GetWorld()->GetGameInstance();
			check(GameInstance);

			UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
			check(WorldStateSubSystem);

			WorldStateSubSystem->Cubicles.Enqueue(Cubicle);
			WorldStateSubSystem->TotalFreeCubicles++;
		}

	}

}
