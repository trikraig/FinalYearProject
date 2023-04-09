// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/Subsystem.h"
#include "GoapAction.h"
#include "Hospital/Patient.h"
#include "WorldStateSubSystem.generated.h"

/**
 *
 */
UCLASS()
class FINALYEARPROJECT_API UWorldStateSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UWorldStateSubSystem();

	Dictionary GetWorldState();

	void AddState(const FString& NewState, bool bSetting);
	void RemoveState(const FString& NewState);

public:
	Dictionary WorldState;

	TQueue<APatient*> WaitingPatients;

};
