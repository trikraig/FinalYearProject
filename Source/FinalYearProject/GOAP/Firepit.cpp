// Fill out your copyright notice in the Description page of Project Settings.


#include "Firepit.h"
#include "WorldStateSubSystem.h"

// Sets default values
AFirepit::AFirepit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirepit::BeginPlay()
{
	Super::BeginPlay();

	Duration = BurnTime;
}

// Called every frame
void AFirepit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bBurning)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Fire Burning")));
		Duration -= DeltaTime;
		if (Duration < 0)
		{
			Duration = 0;
			bBurning = false;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Fire Extinguished")));

			UGameInstance* GameInstance = GetWorld()->GetGameInstance();
			check(GameInstance);

			UWorldStateSubSystem* WorldStateSubSystem = GameInstance->GetSubsystem<UWorldStateSubSystem>();
			check(WorldStateSubSystem);

			WorldStateSubSystem->RemoveState("HasFire");
		}
	}

}

