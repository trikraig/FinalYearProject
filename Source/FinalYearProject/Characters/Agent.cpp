// Fill out your copyright notice in the Description page of Project Settings.

#include "Agent.h"
#include "FinalYearProject/Technique 1/ActionPlanner.h"

// Sets default values
AAgent::AAgent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

// Called to bind functionality to input
void AAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

