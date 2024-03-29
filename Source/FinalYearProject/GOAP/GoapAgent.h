// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GoapPlanner.h"
#include "InventoryComponent.h"
#include "GoapAgent.generated.h"

UCLASS()
class FINALYEARPROJECT_API AGoapAgent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGoapAgent();

	UPROPERTY()
	UGoapPlanner* Planner = nullptr;

	UPROPERTY()
	UInventoryComponent* Inventory = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Any actions that can be performed by this type of agent
	virtual void AddAvailableActions();
	//End desired goal - e.g. BeCured
	virtual void AddGoals();
	//Starting state.
	virtual void SetInitialState();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	enum GameStates { IDLE, MOVETO, PERFORMACTION };
	GameStates State = GameStates::IDLE;

	enum GameEvents { ON_ENTER, ON_UPDATE };
	GameEvents Event = GameEvents::ON_ENTER;

	void FSMUpdate(float DeltaTime);
	void SetFSMState(GameStates newState);

	void Idle_Enter();
	void Idle_Update();
	void Idle_Exit();

	void MoveTo_Enter();
	void MoveTo_Update();
	void MoveTo_Exit();

	void PerformAction_Enter();
	void PerformAction_Update(float DeltaTime);
	void PerformAction_Exit();
};
