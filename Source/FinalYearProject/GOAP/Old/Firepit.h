// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Firepit.generated.h"

UCLASS()
class FINALYEARPROJECT_API AFirepit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFirepit();

	UPROPERTY()
	bool bBurning = false;
	UPROPERTY()
	float Duration = 0.0f;
	UPROPERTY()
	float BurnTime = 50.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
