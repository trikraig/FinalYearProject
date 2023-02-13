// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"

Action::Action(FString _Name, float _Value) : Name(_Name), Value(_Value)
{
}

float Action::GetGoalChange(const Goal& goal)
{
	return goal.Value - Value;
}

