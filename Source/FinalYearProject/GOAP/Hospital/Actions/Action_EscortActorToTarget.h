// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAction.h"
#include "FinalYearProject/GOAP/GoapAgent.h"
#include "Action_EscortActorToTarget.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UAction_EscortActorToTarget : public UGoapAction
{
	GENERATED_BODY()

public:

	FName TagName;
	TSubclassOf<AGoapAgent> TargetClass;

	FString TargetActorConditionKey;
	bool bTargetActorConditionValue;

public:
	UAction_EscortActorToTarget();

protected:

	bool RequiresInRange() override;
	virtual bool CheckProceduralPrecondition(AActor* Agent) override;
	bool Perform(AActor* Agent, float Deltatime) override;

protected:

	AGoapAgent* EscortedAgent = nullptr;
	
};
