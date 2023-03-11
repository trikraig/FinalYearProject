// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"

Action::Action()
{
}

bool Action::IsValid() const
{
	return true;
}

int Action::GetCost() const
{
	return 1000;
}

AActor* Action::GetDestination() const
{
	return nullptr;
}
