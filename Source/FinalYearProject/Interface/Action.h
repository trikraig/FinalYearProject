// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Goal.h"

/**
  Effect an Action will have. 

  #TODO - Need to handle multiple values and needs.

 */
class FINALYEARPROJECT_API Action
{
public: /*Variables*/

	FString Name; //Sleep, Eat, etc...
	float Value = 1.0f; //Amount will have an effect on a Need.

public: /*Functions*/
	Action(FString _Name, float _Value);
	float GetGoalChange(const Goal& goal);

};
