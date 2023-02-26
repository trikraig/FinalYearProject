// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FinalYearProject/Interface/NeedsSystem.h"
#include "ActionPlanner.generated.h"

struct FNeed;

USTRUCT()
struct FAction
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name = "Action";

	UPROPERTY()
	ENeedType Type;

	UPROPERTY()
	float Value = 0.0f;

	float GetNeedChange(const FNeed& Need) const;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALYEARPROJECT_API UActionPlanner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActionPlanner();

	UPROPERTY(EditAnywhere)
	TArray<FAction> Actions;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FAction* ChooseAction(const TArray<FNeed>& Needs);
	float Discontentment(const FAction& Action, const TArray<FNeed>& Needs) const;
		
};
