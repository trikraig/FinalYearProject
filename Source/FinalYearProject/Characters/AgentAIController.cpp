// Fill out your copyright notice in the Description page of Project Settings.


#include "AgentAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "FinalYearProject/Interface//Station.h"

void AAgentAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AAgentAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	//GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::GoToRandomWaypoint, 1.0f, false);
}

void AAgentAIController::GoToTarget()
{
	MoveToActor(TargetLocation);
}
