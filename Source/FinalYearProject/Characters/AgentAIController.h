// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "AgentAIController.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API AAgentAIController : public AAIController
{
	GENERATED_BODY()

public:

	void BeginPlay() override;

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;


	UPROPERTY()
	AActor* TargetLocation;

	UFUNCTION()
	void GoToTarget();

private:
	FTimerHandle TimerHandle;
	
};
