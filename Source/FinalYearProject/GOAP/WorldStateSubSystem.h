// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/Subsystem.h"
#include "GoapAction.h"
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
	virtual void Initialize(FSubsystemCollectionBase& Collection);

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() {}

	Dictionary GetWorldState();
	Dictionary GetGoalState();

	void AddState(const FString& NewState, bool bSetting);
	void RemoveState(const FString& NewState);

	void AddGoal(const FString& NewGoal, bool bSetting);
	void RemoveGoal(const FString& Goal);

protected:

	Dictionary WorldState;

	Dictionary GoalState;
};
