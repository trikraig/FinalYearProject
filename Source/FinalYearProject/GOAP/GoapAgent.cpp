// Fill out your copyright notice in the Description page of Project Settings.

#include "GoapAgent.h"
#include "WorldStateSubSystem.h"
#include "../Characters/AgentAIController.h"

// Sets default values
AGoapAgent::AGoapAgent()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup Planner Component
	Planner = CreateDefaultSubobject<UGoapPlanner>(TEXT("GOAP Planner Component"));
}

// Called when the game starts or when spawned
void AGoapAgent::BeginPlay()
{
	Super::BeginPlay();

	//Will initialize planner from here. 
	//Each Agent will be unique with different actions.
	//Easier to make this the common point of divergence for each agent type
	AddAvailableActions();
	AddGoals();
	SetInitialState();
}

void AGoapAgent::AddAvailableActions()
{
	check(Planner);

	//Example Action Being added 
	//Planner->AvailableActions.Add(NewObject<UChopTreeAction>());
	//Planner->AvailableActions.Add(NewObject<UGiveToolAction>());
	//Planner->AvailableActions.Add(NewObject<UBuildFire>());
}

void AGoapAgent::AddGoals()
{
	check(Planner);

	//Example goal 
	//Planner->AddGoal(TEXT("HasFire"), true);
}

void AGoapAgent::SetInitialState()
{
	check(Planner);

	//Example beginning state. - MUST INCLUDE FALSE CONDITIONS.
	//Planner->AddState("HasFire", false);
	//Planner->AddState("HasFirewood", false);
	//Planner->AddState("HasTool", false); //likely need to override world state with current state of agent, e.g. has tool.
}

// Called every frame
void AGoapAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FSMUpdate(DeltaTime);
}

// Called to bind functionality to input
void AGoapAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGoapAgent::FSMUpdate(float DeltaTime)
{
	switch (State)
	{
	case AGoapAgent::IDLE:
	{
		if (Event == GameEvents::ON_ENTER) {
			Idle_Enter();
		}
		if (Event == GameEvents::ON_UPDATE) {
			Idle_Update();
		}
		break;
	}

	case AGoapAgent::MOVETO:
	{
		if (Event == GameEvents::ON_ENTER) {
			MoveTo_Enter();
		}
		if (Event == GameEvents::ON_UPDATE) {
			MoveTo_Update();
		}
		break;
	}

	case AGoapAgent::PERFORMACTION:
	{
		if (Event == GameEvents::ON_ENTER) {
			PerformAction_Enter();
		}
		if (Event == GameEvents::ON_UPDATE) {
			PerformAction_Update(DeltaTime);
		}
		break;
	}
	}
}

void AGoapAgent::SetFSMState(GameStates newState)
{
	switch (State)
	{
	case AGoapAgent::IDLE: Idle_Exit(); break;
	case AGoapAgent::MOVETO: MoveTo_Exit(); break;
	case AGoapAgent::PERFORMACTION: PerformAction_Exit(); break;
	default: UE_LOG(LogTemp, Error, TEXT("Unexpected state has not been implemented!"), newState); break;
	}

	// Set new GameStates state and begin OnEnter of that state
	State = newState;
	Event = GameEvents::ON_ENTER;
}

void AGoapAgent::Idle_Enter()
{
	// Change to GameEvents to Update when called
	Event = GameEvents::ON_UPDATE;
}

void AGoapAgent::Idle_Update()
{
	//Planner Should be empty

	bool bResult = Planner->Plan();

	if (bResult)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Plan Generated")));
		SetFSMState(PERFORMACTION);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Plan Failed")));
		SetFSMState(IDLE);
	}
}

void AGoapAgent::Idle_Exit()
{
	// Implement any functionality for leaving the Idle state
}

void AGoapAgent::MoveTo_Enter()
{
	// Change to GameEvents to Update when called
	Event = GameEvents::ON_UPDATE;
}

void AGoapAgent::MoveTo_Update()
{
	//Have AI handle Movement to Target Actor.

	UGoapAction* Action = nullptr;
	Planner->CurrentActions.Peek(Action);
	check(Action);

	if (AAgentAIController* AI = Cast<AAgentAIController>(GetController()))
	{
		if (Action->TargetObject)
		{
			AI->MoveToActor(Action->TargetObject);

			if (Action->IsInRange(this))
			{
				//Mark that we are in range of action.
				Action->SetInRange(true);
				//Now can perform action.
				SetFSMState(PERFORMACTION);
			}
		
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("No Target Actor")));
		}
	}
}

void AGoapAgent::MoveTo_Exit()
{
	// Implement any functionality for leaving the MoveTo state
}

void AGoapAgent::PerformAction_Enter()
{
	check(Planner);
	// Change to GameEvents to Update when called
	Event = GameEvents::ON_UPDATE;
}

void AGoapAgent::PerformAction_Update(float DeltaTime)
{
	//Will be performing the Goap Action as per Action::Perform .

	//Peek at item at back of queue, 
	UGoapAction* Action = nullptr;
	Planner->CurrentActions.Peek(Action);

	//Check this and shouldnt be done already.

	if (Action && Action->IsDone())
	{
		//the action is already done, can be removed from queue.
		Planner->CurrentActions.Dequeue(Action);
	}


	if (Planner->PlanAvailable())
	{
		//Perform the next action.
		Planner->CurrentActions.Peek(Action);
		check(Action);
		bool bInRange = Action->RequiresInRange() ? Action->IsInRange() : true;

		if (bInRange)
		{
			//We are in range so can perform the action
			bool bSucess = Action->Perform(this, DeltaTime);
			if (!bSucess)
			{
				//action failed so need to abort and replan
				SetFSMState(IDLE);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Action Failed - Plan Aborted")));
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Performing Action")));
			}
		}
		else
		{
			//Need to get in range of action
			SetFSMState(MOVETO);
		}
	}
	else
	{
		//No actions left. Return to idle state to replan
		SetFSMState(IDLE);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("No actions left - Returning to Idle")));

	}
}

void AGoapAgent::PerformAction_Exit()
{
	// Implement any functionality for leaving the Exit state
}