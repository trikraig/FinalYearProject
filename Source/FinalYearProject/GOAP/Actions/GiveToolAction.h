// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAction.h"
#include "GiveToolAction.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UGiveToolAction : public UGoapAction
{
	GENERATED_BODY()

public:

	TSubclassOf<AActor> ToolClass;

private:

	bool bGivenTool = false;

	AActor* Tool = nullptr;

public:

	UGiveToolAction();

	virtual void Reset() override;

	virtual bool IsDone() override;

	virtual bool RequiresInRange() override;

	virtual bool CheckProceduralPrecondition(AActor* Agent) override;

	virtual bool Perform(AActor* Agent) override;
	
};
