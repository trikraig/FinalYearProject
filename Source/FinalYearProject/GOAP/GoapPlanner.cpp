// Fill out your copyright notice in the Description page of Project Settings.

#include "GoapPlanner.h"
#include "WorldStateSubSystem.h"
#include "GoapAgent.h"
#include "Actions/ChopTreeAction.h"
#include "Actions/GiveToolAction.h"

// Sets default values for this component's properties
UGoapPlanner::UGoapPlanner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	//AvailableActions.Add(&UChopTreeAction());
	//AvailableActions.Add(&UGiveToolAction());



}

// Called when the game starts
void UGoapPlanner::BeginPlay()
{
	Super::BeginPlay();

	// ...

	AvailableActions.Add(NewObject<UChopTreeAction>());
	AvailableActions.Add(NewObject<UGiveToolAction>());
}

// Called every frame
void UGoapPlanner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UGoapPlanner::Plan()
{
	//Get World State and and the Goal we want to plan for.
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	check(GameInstance);

	UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
	check(WorldStateSubSystem);

	auto WorldState = WorldStateSubSystem->GetWorldState();
	auto GoalState = WorldStateSubSystem->GetGoalState();

	AGoapAgent* Agent = Cast<AGoapAgent>(GetOwner());
	check(Agent);

	//Reset Existing Actions.
	CurrentActions.Empty();

	//Check what actions can run using their checkProceduralPrecondition
	TSet<UGoapAction*> UsableActions;

	for (auto& Action : AvailableActions)
	{
		if (Action->CheckProceduralPrecondition(Agent))
			UsableActions.Add(Action);
	}

	// we now have all actions that can run, stored in usableActions

	// build up the tree and record the leaf nodes that provide a solution to the goal.
	TArray<Node*> Leaves;

	// build graph
	Node* RootNode = new Node(nullptr, 0, WorldState, nullptr);
	bool bSuccess = BuildGraph(RootNode, Leaves, UsableActions, GoalState);

	if (!bSuccess)
	{
		//No plan found.
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("NO PLAN FOUND")));
		return false;
	}

	//Plan found! - Find the cheapest leaf

	Node* Cheapest = nullptr;
	for (Node* Leaf : Leaves)
	{
		if (!Cheapest || Leaf->RunningCost < Cheapest->RunningCost)
		{
			Cheapest = Leaf;
		}
	}

	// Start at cheapest leaf, work way up tree adding required actions to queue.
	CurrentActions.Empty();
	Node* n = Cheapest;

	while (n != nullptr)
	{
		if (n->Action != nullptr)
		{
			CurrentActions.Enqueue(n->Action);
		}
		n = n->Parent;
	}

	for (auto& Leaf : Leaves)
	{
		delete Leaf;
	}

	return !CurrentActions.IsEmpty();

}

bool UGoapPlanner::BuildGraph(Node* Parent, TArray<Node*>& Leaves, const TSet<UGoapAction*>& UsableActions, const Dictionary& Goal)
{
	bool bSolutionFound = false;

	//Iterate through each action available at node and see if we can use it here

	for (UGoapAction* Action : UsableActions)
	{
		// if the parent state has the conditions for this action's preconditions, we can use it here
		if (InState(Action->GetConditions(), Parent->State))
		{
			// apply the action's effects to the parent state
			Dictionary CurrentState = PopulateState(Parent->State, Action->GetEffects());

			Node* NextNode = new Node(Parent, Parent->RunningCost + Action->Cost, CurrentState, Action);
			if (InState(Goal, CurrentState))
			{
				// Solution Found
				Leaves.Add(NextNode);
				bSolutionFound = true;
			}
			else
			{
				//Not found solution yet, so test all remaining actions and branch out the tree.
				TSet<UGoapAction*> Subset = ActionSubset(UsableActions, Action);
				if (BuildGraph(NextNode, Leaves, Subset, Goal))
					bSolutionFound = true;
			}

		}
	}

	return bSolutionFound;
}

bool UGoapPlanner::InState(const Dictionary& Test, const Dictionary& State)
{

	for (const TPair<FString, bool>& TestPair : Test)
	{
		bool bMatch = false;

		for (const TPair<FString, bool>& StatePair : State)
		{
			if (StatePair.Key == TestPair.Key &&
				StatePair.Value == TestPair.Value)
			{
				bMatch = true;
			}
		}

		//If any state condition not met, set return value to false.
		if (!bMatch) 
			return false;

	}

	return true;
}

Dictionary UGoapPlanner::PopulateState(const Dictionary& CurrentState, const Dictionary& StateChange)
{
	Dictionary ReturnState = CurrentState;
	ReturnState.Append(StateChange);
	return ReturnState;
}

TSet<UGoapAction*> UGoapPlanner::ActionSubset(TSet<UGoapAction*> Actions, UGoapAction* SkipAction)
{
	TSet<UGoapAction*> ReturnSet;

	for (UGoapAction* Action : Actions)
	{
		if (Action == SkipAction) continue;
		ReturnSet.Add(Action);
	}

	return ReturnSet;
}

