// Fill out your copyright notice in the Description page of Project Settings.



#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FinalYearProject/Core/Defines.h"
#include "FinalYearProject/Interface/NeedsSystem.h"
#include "../Technique 1/Action.h"
#include "Agent.generated.h"

UCLASS()
class FINALYEARPROJECT_API AAgent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAgent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public: /*Variables*/

	UPROPERTY(BlueprintReadWrite)
	class UNeedsSystem* NeedsSystemComponent;

#ifndef _TECH1
	//Declare Technique 1 Action Planner
	class UActionPlanner* ActionPlannerComponent;
#endif

	UPROPERTY()
	float Speed = 10.0f;

public:	/*Functions*/
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector Direction;

	Action* CurrentAction;
};