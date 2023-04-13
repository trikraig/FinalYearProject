// Fill out your copyright notice in the Description page of Project Settings.


#include "Action_GoToWaitingRoom.h"
#include "FinalYearProject/GOAP/Hospital/Patient.h"
#include "../../WorldStateSubSystem.h"


void UAction_GoToWaitingRoom::PostPerform(AActor* Actor)
{
	Super::PostPerform(Actor);

	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	check(GameInstance);

	UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
	check(WorldStateSubSystem);

	auto WorldState = WorldStateSubSystem->GetWorldState();

	APatient* Patient = Cast<APatient>(Actor);
	check(Patient);

	WorldStateSubSystem->WaitingPatients.Enqueue(Patient);
}