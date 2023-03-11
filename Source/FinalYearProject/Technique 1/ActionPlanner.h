// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FinalYearProject/Interface/NeedsSystem.h"
#include "FinalYearProject/Interface/Station.h"
#include "FinalYearProject/Technique 1/Action.h"
#include "FinalYearProject/Characters/Agent.h"
#include "ActionPlanner.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALYEARPROJECT_API UActionPlanner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActionPlanner();

	TArray<Action> Actions;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Create actions that would meet target need.
	void CreateActions(const FNeed& TargetNeed);
	// Create actions that would fulfill conditions of Target Station.
	void CreateActions(AStation* TargetStation);

	bool FindNewAction(AAgent* Agent);
		
};
