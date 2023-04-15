// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAction.h"
#include "Action_GoToActorWithTag.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UAction_GoToActorWithTag : public UGoapAction
{
	GENERATED_BODY()

public:

	FName TagName;

public:
	UAction_GoToActorWithTag();

protected:

	bool RequiresInRange() override;
	virtual bool CheckProceduralPrecondition(AActor* Agent);
	virtual bool Perform(AActor* Agent, float Deltatime);
	
};
