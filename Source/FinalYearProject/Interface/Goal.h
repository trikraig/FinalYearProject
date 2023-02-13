// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
	Will be individual Goal, will be contained in Needs System as a TArray.
	Should be easy to increase
	Will need Name, Values etc
 */
class FINALYEARPROJECT_API Goal
{
public: /*Variables*/

	FString Name; //Energy, Hunger, etc...
	float Value = 0.0f; //0 - Need Met, 1 - Need Needs fulfillment

public: /*Functions*/
	Goal(FString _Name);
};
