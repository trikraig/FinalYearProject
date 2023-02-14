// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Goal.h"

float UAction::GetGoalChange(const UGoal& _Goal)
{
	return _Goal.Value - Value;
}
