// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

/**
 *  
 */
class FINALYEARPROJECT_API Action
{
public:
	Action();

AActor* DestinationActor = nullptr;

/*Is this a valid action or not (affected by world state)*/
virtual bool IsValid() const;

/*Action Cost - Situation cost for Action depending on world state - i.e check distance to object etc. */
virtual int GetCost() const;

/*Action Requirements - Example - Check Resource Requirement - Would return a TMap of conditions that satisfies .*/
//virtual void GetPreConditions() const;
//
///*What conditions this action satisfies.*/
//virtual void GetEffects() const;

/*Similar to perform and have actor load into.*/
virtual AActor* GetDestination() const;


};
