// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/GoapAgent.h"
#include "Patient.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API APatient : public AGoapAgent
{
	GENERATED_BODY()

protected:
	//Any actions that can be performed by this type of agent
	void AddAvailableActions() override;
	//End desired goal - e.g. BeCured
	void AddGoals() override;
	//Starting state.
	void SetInitialState() override;
public:
	void SendToBeCured(AActor* Cubicle);
};
