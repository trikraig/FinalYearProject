// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Action.generated.h"

UCLASS()
class FINALYEARPROJECT_API UAction : public UObject
{
	GENERATED_BODY()

public: /*Variables*/
FString Name = TEXT("Example");
float Value = 0.1f;

/*Functions*/

float GetGoalChange(const class UGoal& _Goal);
	
};
