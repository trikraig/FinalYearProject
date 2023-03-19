// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "GoapAction.h"
#include "GoapAgent.generated.h"

UCLASS()
class FINALYEARPROJECT_API AGoapAgent : public ACharacter
{
	GENERATED_BODY()

protected:

	//TSet<UGoapAction> AvailableActions;
	//TQueue<UGoapAction> CurrentActions;

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

};
