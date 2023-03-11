// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NeedsSystem.generated.h"

UENUM(BlueprintType)
enum class ENeedType : uint8
{
	Energy,
	Count UMETA(Hidden)
};

ENUM_RANGE_BY_COUNT(ENeedType, ENeedType::Count);

USTRUCT(BlueprintType)
struct FNeed
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FString Name = "Need";

	UPROPERTY()
	ENeedType Type;

	UPROPERTY()
	float Value = 60.0f;

	UPROPERTY()
	float Discontentment = 50.0f;

	inline bool IsDiscontent() const { return Value > Discontentment; };
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALYEARPROJECT_API UNeedsSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNeedsSystem();

public: /*Variables*/

	//UPROPERTY(EditAnywhere)
	//TArray<FNeed> Needs;

	UPROPERTY(EditAnywhere)
	TMap<ENeedType, FNeed> NeedsMap;

	UPROPERTY(BlueprintReadOnly)
	float TimeTick = 0.0f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Tick_Need(float DeltaTime, FNeed& Goal); 

	void FufillNeed(const ENeedType& NeedType, float Amount);
		
};
