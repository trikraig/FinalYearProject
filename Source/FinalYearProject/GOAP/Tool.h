// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tool.generated.h"

/*
Very bare bones class, but using instead of setting a target class in desired action via UProperty. 
Likely a much nicer way to avoid needing this, but at least can create BP from and place in level.
*/

UCLASS()
class FINALYEARPROJECT_API ATool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATool();

};
