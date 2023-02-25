// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Station.h"
#include "Resource.h"
#include "NeedsSystem.h"
#include "Provider.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API AProvider : public AStation
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	TEnumAsByte<ResourceTypes> InputResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	TEnumAsByte<NeedTypes> OutputNeed;
	
};
