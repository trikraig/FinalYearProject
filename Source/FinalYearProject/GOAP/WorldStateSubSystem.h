// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/Subsystem.h"
#include "GoapAction.h"
#include "Hospital/Patient.h"
#include "Containers/CircularQueue.h"
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

	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	Dictionary GetWorldState();

	void AddState(const FString& NewState, bool bSetting);
	void RemoveState(const FString& NewState);


public:

	Dictionary WorldState;

	TQueue<APatient*> Patients;
	TQueue<AActor*> Cubicles;

	UPROPERTY(BlueprintReadOnly)
	int32 TotalWaitingPatients = 0;

};
