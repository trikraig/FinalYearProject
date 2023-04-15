// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalYearProject/GOAP/Hospital/Actions/Action_GoToActorWithTag.h"
#include "Action_GoToWaitingRoom.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UAction_GoToWaitingRoom : public UAction_GoToActorWithTag
{
	GENERATED_BODY()

public:

	void PostPerform(AActor* Actor) override;

};
