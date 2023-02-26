// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Station.generated.h"

UCLASS()
class FINALYEARPROJECT_API AStation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStation();

	UPROPERTY()
	TArray<AActor*> Workers;

	UPROPERTY()
	float fProgress = 0.0f;
	UPROPERTY()
	float fProgressRate = 1.0f;

	// create trigger capsule
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
	class UCapsuleComponent* TriggerCapsule;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void AddWorker(AActor* Worker);

	UFUNCTION()
	void RemoveWorker(AActor* Worker);

	UFUNCTION()
	virtual void OnProgressCompletion();

	UFUNCTION()
	virtual void Reset(); 

	UFUNCTION()
	virtual bool RequirementsMet();

};
