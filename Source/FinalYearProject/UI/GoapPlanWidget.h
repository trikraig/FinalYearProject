// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GoapPlanWidget.generated.h"

/**
 * 
 */
UCLASS()
class FINALYEARPROJECT_API UGoapPlanWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent)
	void AddPlanItem(const FText& Name);

	UFUNCTION(BlueprintImplementableEvent)
	void ClearPlanItems();
	
};
