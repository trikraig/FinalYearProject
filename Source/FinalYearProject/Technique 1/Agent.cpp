// Fill out your copyright notice in the Description page of Project Settings.

#include "Agent.h"
#include "FinalYearProject/Technique 1/ActionPlanner.h"
#include "../Characters/AgentAIController.h"


// Sets default values
AAgent::AAgent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup Needs System Component
	NeedsSystemComponent = CreateDefaultSubobject<UNeedsSystem>(TEXT("Needs System Component"));

#ifndef _TECH1
	//Setup Action Planner Component
	ActionPlannerComponent = CreateDefaultSubobject<UActionPlanner>(TEXT("Technique 1 Action Planner Component"));
#endif

}

// Called when the game starts or when spawned
void AAgent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Do we have an action?
	if (CurrentAction)
	{
		if (AAgentAIController* AI = Cast<AAgentAIController>(GetController()))
		{
			if (AI->TargetLocation == NULL)
			{
				AI->TargetLocation = CurrentAction->DestinationActor;
			}

			if (AI->TargetLocation)
				AI->GoToTarget();
		}
	}
	else
	{
		ActionPlannerComponent->FindNewAction(this);
	}

	//Act upon that action.
}

// Called to bind functionality to input
void AAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

