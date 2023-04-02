// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAction.h"
#include "BuildFire.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UBuildFire : public UGoapAction
{
	GENERATED_BODY()

private:

	bool bBuiltFire = false;
	AActor* FirePit = nullptr;
	float Progress = 0;
	float WorkDuration = 10.0f;

public:

	UBuildFire();
	virtual void Reset() override;
	virtual bool IsDone() override;
	virtual bool RequiresInRange() override;
	virtual bool CheckProceduralPrecondition(AActor* Agent) override;
	virtual bool Perform(AActor* Agent, float Deltatime) override;
	
};
