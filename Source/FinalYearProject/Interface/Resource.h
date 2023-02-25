// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resource.generated.h"

UENUM()
enum class EResourceType : uint8
{
	RawFood,
	Ingredients,
	Food,
	Count UMETA(Hidden)
};

ENUM_RANGE_BY_COUNT(EResourceType, EResourceType::Count);

class FINALYEARPROJECT_API Resource 
{	
public:	
	// Sets default values for this actor's properties
	Resource();

	FString Name = "Resource";

	uint8 Type;

	int32 Quantity = 0;

};
