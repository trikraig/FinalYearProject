// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FinalYearProject/Interface/Goal.h"
#include "NeedsSystem.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALYEARPROJECT_API UNeedsSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNeedsSystem();
	~UNeedsSystem();

public: /*Variables*/

	UPROPERTY(EditAnywhere)
	TArray<TObjectPtr<UGoal>> Needs;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Tick_Goal(float DeltaTime, UGoal* Goal); 
		
};
