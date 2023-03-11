// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Station.h"
#include "Resource.h"
#include "Processor.generated.h"

/**
 * Processes an Input Resource into an output Resource
 */

UCLASS()
class FINALYEARPROJECT_API AProcessor : public AStation
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	EResourceType InputResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	int InputQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	EResourceType OutputResourceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	int OutputQuantity;

public:

	virtual bool RequirementsMet() override;
	virtual void OnProgressCompletion() override;
	
};
