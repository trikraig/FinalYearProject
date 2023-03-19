// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GoapAction.h"
#include "GoapAgent.generated.h"

UCLASS()
class FINALYEARPROJECT_API AGoapAgent : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	TSet<UGoapAction*> AvailableActions;


	TQueue<UGoapAction*> CurrentActions;

public:
	// Sets default values for this character's properties
	AGoapAgent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

	void FSMUpdate();
	void SetFSMState(GameStates newState);

	void Idle_Enter();
	void Idle_Update();
	void Idle_Exit();

	void MoveTo_Enter();
	void MoveTo_Update();
	void MoveTo_Exit();

	void PerformAction_Enter();
	void PerformAction_Update();
	void PerformAction_Exit();

};
