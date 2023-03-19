// Fill out your copyright notice in the Description page of Project Settings.


#include "GoapAgent.h"

// Sets default values
AGoapAgent::AGoapAgent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	//Get World State
	//Get World Conditions
	TMap<FString, bool> WorldState; // = WorldState->GetWorldState - //Get list of conditions in world. Generate from collected resources etc.
	TMap<FString, bool> Goal; //WorldState->CreateGoalState -- Get Desired Conditions

	//Plan

	//TQueue<UGoapAction> Plan; // Planner - Get Generated Queue of Actions to completed

	//if (!Plan.IsEmpty())
	{
		//We have a plan! Yay!

		//Move contents of Plan into CurrentActions.

		//Inform WorldState that we have a plan 
	}

	//Act upon that action.

	//if has action
	//	//move to action

		//perform action

	// else idle



}

// Called to bind functionality to input
void AGoapAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

