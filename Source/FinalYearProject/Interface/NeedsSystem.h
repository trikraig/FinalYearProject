// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NeedsSystem.generated.h"

UENUM()
enum NeedTypes
{
	NONE = 0	UMETA(Hidden),
	ENERGY,
	NUM			UMETA(Hidden)
};

USTRUCT()
struct FNeed
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name = "Need";

	UPROPERTY()
	TEnumAsByte<NeedTypes> Type;

	UPROPERTY()
	float Value = 0.0f;

	float GetDiscontentment(float NewValue) const;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALYEARPROJECT_API UNeedsSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNeedsSystem();

public: /*Variables*/

	UPROPERTY(EditAnywhere)
	TArray<FNeed> Needs;

	UPROPERTY(BlueprintReadOnly)
	float TimeTick = 0.0f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Tick_Goal(float DeltaTime, FNeed& Goal); 
		
};
