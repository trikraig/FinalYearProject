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

	//With my implementation, i wanted to avoid having to define each individual action manually, and instead generate them all programatically.
	// Create actions that would meet target need.
	void PlanActions(const FNeed& TargetNeed);
	//Could introduce a input required station type that parent provider and processor but make do with these two for now.
	void PlanActions(TArray<AActor*> FoundStations, class AProvider* RequiredProvider);
	void PlanActions(TArray<AActor*> FoundStations, class AProcessor* RequiredProcessor);

	// Plan actions that would fulfill conditions of Target Station.

	void CreateAction(AActor* TargetStation);


	bool FindNewAction(AAgent* Agent);
		
};
