// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resource.h"
#include "ResourceManager.generated.h"

UCLASS()
class FINALYEARPROJECT_API AResourceManager : public AActor
{
	GENERATED_BODY()

public:

	TArray<Resource*> Resources;
	
public:	
	// Sets default values for this actor's properties
	AResourceManager();
	~AResourceManager();

	FString GetName(EResourceType Type);

	void AddResource(EResourceType Type, int Quantity);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	virtual void Tick(float DeltaSeconds) override;

};
