// Fill out your copyright notice in the Description page of Project Settings.

#include "GoapAgent.h"
#include "WorldStateSubSystem.h"

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
}

// Called every frame
void AGoapAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FSMUpdate();
}

// Called to bind functionality to input
void AGoapAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGoapAgent::FSMUpdate()
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
			PerformAction_Update();
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

	//TODO - Planner
	Planner->Plan();
}

void AGoapAgent::Idle_Update()
{
	//Do nothing
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
}

void AGoapAgent::MoveTo_Exit()
{
	// Implement any functionality for leaving the MoveTo state
}

void AGoapAgent::PerformAction_Enter()
{
	// Change to GameEvents to Update when called
	Event = GameEvents::ON_UPDATE;
}

void AGoapAgent::PerformAction_Update()
{
	//Will be performing the Goap Action as per Action::Perform .
}

void AGoapAgent::PerformAction_Exit()
{
	// Implement any functionality for leaving the Exit state
}