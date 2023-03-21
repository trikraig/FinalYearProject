// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GoapAction.generated.h"

typedef TMap<FString, bool> Dictionary;

/**
 *
 */
UCLASS()
class FINALYEARPROJECT_API UGoapAction : public UObject
{
	GENERATED_BODY()
public:

	UGoapAction() {};

protected:

	Dictionary Preconditions;
	Dictionary Effects;

	bool bInRange = false;

public:

	/* The cost of performing the action.
	* Figure out a weight that suits the action.
	* Changing it will affect what actions are chosen during planning. */
	float Cost;

	/*Range required to be set as In Range of the TargetObject*/
	float Range = 10.0f;

	/* An action often has to perform on an object. This is that object. Can be null. */
	AActor* TargetObject = nullptr;

public:

	void DoReset();

	/*Reset any variables that need to be reset before planning happens again.*/
	virtual void Reset();

	/* Is the action done? */
	virtual bool IsDone();

	/**
	* Procedurally check if this action can run. Not all actions
	* will need this, but some might.
	*/
	virtual bool CheckProceduralPrecondition(AActor* Agent);

	/**
	* Run the action.
	 * Returns True if the action performed successfully or false
	 * if something happened and it can no longer perform. In this case
	 * the action queue should clear out and the goal cannot be reached.
	 */
	virtual bool Perform(AActor* Agent);

	/**
	* Does this action need to be within range of a target game object?
	* If not then the moveTo state will not need to run for this action.
	*/
	virtual bool RequiresInRange();

	bool IsInRange() const { return bInRange; };

	bool IsInRange(AActor* Agent) const;

	void SetInRange(bool bInput) { bInRange = bInput; };

	void AddPrecondition(FString Key, bool bValue);

	void RemovePrecondition(FString Key);

	void AddEffect(FString Key, bool bValue);

	void RemoveEffect(FString Key);

	Dictionary GetConditions();
	Dictionary GetEffects();

	bool SetDestinationActorToTargetClass(AActor* Agent, TSubclassOf<AActor> TargetClass);
};
