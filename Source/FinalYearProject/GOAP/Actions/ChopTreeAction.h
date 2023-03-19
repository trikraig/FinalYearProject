// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAction.h"
#include "ChopTreeAction.generated.h"

/**
 *
 */
UCLASS()
class FINALYEARPROJECT_API UChopTreeAction : public UGoapAction
{
	GENERATED_BODY()

public:

	TSubclassOf<AActor> ChoppingBlockClass;

private:

	bool bChopped = false;

	AActor* ChoppingBlock = nullptr;

	float StartTimer = 0;
	float WorkDuration = 2.0f; //Seconds

public:

	UChopTreeAction();

	virtual void Reset() override;

	virtual bool IsDone() override;

	virtual bool RequiresInRange() override;

	virtual bool CheckProceduralPrecondition(AActor* Agent) override;

	virtual bool Perform(AActor* Agent) override;
};
