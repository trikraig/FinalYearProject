// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoapAction.h"
#include "GoapPlanner.generated.h"

/**
 * Used for building up the graph and holding the running costs of actions.
 */
class Node
{
public:
	Node* Parent;
	TArray<TUniquePtr<Node>> Children;
	float RunningCost;
	Dictionary State;
	UGoapAction* Action;

	Node(Node* _parent, float _runningcost, const Dictionary& _state, UGoapAction* _action)
	{
		Parent = _parent;
		RunningCost = _runningcost;
		State = _state;
		Action = _action;
	}
	~Node()
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Node Memory Released")));
	}
};

/**
 * Plans what actions can be completed in order to fulfill a goal state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FINALYEARPROJECT_API UGoapPlanner : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGoapPlanner();

	UPROPERTY(EditAnywhere)
	TSet<UGoapAction*> AvailableActions;

	TQueue<UGoapAction*> CurrentActions;

	Dictionary GoalState;

	Dictionary CurrentState;

public:

	bool Plan();

	bool PlanAvailable() const;

	void AddGoal(const FString& NewGoal, bool bSetting);
	void RemoveGoal(const FString& Goal);

	void AddState(const FString& NewState, bool bSetting);
	void RemoveState(const FString& State);

	bool InState(const FString& CheckState, bool bValue);

private:

	/**
	 * Returns true if at least one solution was found.
	 * The possible paths are stored in the leaves list. Each leaf has a
	 * 'runningCost' value where the lowest cost will be the best action
	 * sequence.
	 */
	bool BuildGraph(Node* Parent, TArray<Node*>& Leaves, const TSet<UGoapAction*>& UsableActions, const Dictionary& Goal);

	/**
	 * Check that all items in 'test' are in 'state'. If just one does not match or is not there
	* then this returns false.
	*/
	bool InState(const Dictionary& Test, const Dictionary& State);

	/**
	 * Apply the stateChange to the currentState
	 */
	Dictionary PopulateState(const Dictionary& CurrentState, const Dictionary& StateChange);

	/**
	* Create a subset of the actions excluding the removeMe one. Creates a new set.
	*/
	TSet<UGoapAction*> ActionSubset(TSet<UGoapAction*> Actions, UGoapAction* RemoveMe);

};
