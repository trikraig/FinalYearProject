// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAction.h"
#include "Action_GetTreated.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UAction_GetTreated : public UGoapAction
{
	GENERATED_BODY()

public:

	virtual bool CheckProceduralPrecondition(AActor* Agent) override;
	bool RequiresInRange() override;
	void PostPerform(AActor* Actor) override;
	
};
