// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Goal.generated.h"

UCLASS()
class FINALYEARPROJECT_API UGoal : public UObject
{
	GENERATED_BODY()

public: /*Variables*/

	FName Name;
	float Value = 0.0F;

public: /*Functions*/

	UGoal();
	UGoal(FName _Name, float _Value);
	
};
