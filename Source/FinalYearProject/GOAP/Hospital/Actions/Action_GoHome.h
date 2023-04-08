// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAction.h"
#include "Action_GoHome.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UAction_GoHome : public UGoapAction
{
	GENERATED_BODY()
public:

	UAction_GoHome();

protected:

	void AddPreconditions() override;
	void AddEffects() override;	
	bool RequiresInRange() override;
	virtual bool CheckProceduralPrecondition(AActor* Agent) override;
	bool Perform(AActor* Agent, float Deltatime) override;

};
