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
	uint8 InputResourceQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	uint8 RequiredInputQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	ENeedType OutputNeed = ENeedType::Energy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	float NeedFufillmentAmount = 100.0f;

public:

	virtual bool RequirementsMet() override;
	virtual void OnProgressCompletion() override;
	virtual void Reset() override;
	
};
