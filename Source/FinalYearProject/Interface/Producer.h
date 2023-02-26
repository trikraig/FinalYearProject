// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Station.h"
#include "Resource.h"
#include "Producer.generated.h"

/**
 * Producers an output resource.
 */
UCLASS()
class FINALYEARPROJECT_API AProducer : public AStation
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "FYP")
	EResourceType OutputResource;
	
};
