// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resource.generated.h"

UENUM()
enum ResourceTypes
{
	RAWFOOD,
	INGREDIENTS,
	FOOD
};

UCLASS()
class FINALYEARPROJECT_API AResource : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResource();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	FString Name = "Resource";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FYP")
	TEnumAsByte<ResourceTypes> Type = RAWFOOD;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
