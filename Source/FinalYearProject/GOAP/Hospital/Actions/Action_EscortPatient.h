// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/Hospital/Actions/Action_EscortActorToTarget.h"
#include "Action_EscortPatient.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UAction_EscortPatient : public UAction_EscortActorToTarget
{
	GENERATED_BODY()

public:

	void PostPerform(AActor* Actor) override;
	
};
