// Fill out your copyright notice in the Description page of Project Settings.


#include "AgentAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void AAgentAIController::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	GoToRandomWaypoint();
}

void AAgentAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::GoToRandomWaypoint, 1.0f, false);
}

ATargetPoint* AAgentAIController::GetRandomWaypoint()
{
	auto index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[index]);
}

void AAgentAIController::GoToRandomWaypoint()
{
	MoveToActor(GetRandomWaypoint());
}
