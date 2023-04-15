// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAction.h"
#include "Action_GetPatient.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UAction_GetPatient : public UGoapAction
{
	GENERATED_BODY()

public:

	virtual bool CheckProceduralPrecondition(AActor* Agent) override;
	bool RequiresInRange() override;
	void PostPerform(AActor* Actor) override;

	
};
