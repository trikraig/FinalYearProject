// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAgent.h"
#include "Nurse.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API ANurse : public AGoapAgent
{
	GENERATED_BODY()

public:
	void ReadyForNextPatient();

protected:
	//Any actions that can be performed by this type of agent
	void AddAvailableActions() override;
	//End desired goal - e.g. BeCured
	void AddGoals() override;
	//Starting state.
	void SetInitialState() override;
	
};
