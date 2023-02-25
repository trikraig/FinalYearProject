// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FinalYearProject/Characters/Agent.h"
#include "Station.generated.h"

UCLASS()
class FINALYEARPROJECT_API AStation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStation();

	UPROPERTY()
	TArray<AAgent*> Workers;

	UPROPERTY()
	float fProgress = 0.0f;
	UPROPERTY()
	float fProgressRate = 1.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	bool AddWorker(AAgent* Worker);

};
