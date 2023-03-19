// Fill out your copyright notice in the Description page of Project Settings.

#include "GoapPlanner.h"
#include "WorldStateSubSystem.h"
#include "GoapAgent.h"

// Sets default values for this component's properties
UGoapPlanner::UGoapPlanner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGoapPlanner::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UGoapPlanner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGoapPlanner::Plan()
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
	TArray<Node> Leaves;

	// build graph
	Node* RootNode = new Node (nullptr, 0, WorldState, nullptr);
	bool bSuccess = BuildGraph(RootNode, Leaves, UsableActions, GoalState);

}

bool UGoapPlanner::BuildGraph(Node* Parent, TArray<Node>& Leaves, TSet<UGoapAction*> UsableActions, Dictionary Goal)
{
	return true;
}
