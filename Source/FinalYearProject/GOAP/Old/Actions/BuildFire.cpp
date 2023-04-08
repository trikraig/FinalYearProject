// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildFire.h"
#include "../Firepit.h"

UBuildFire::UBuildFire()
{
	AddPrecondition("HasFirewood", true); 
	AddEffect("HasFirewood", false);
	AddEffect("HasFire", true);
}

void UBuildFire::Reset()
{
	bBuiltFire = false;
	FirePit = nullptr;
	Progress = 0.0f;
}

bool UBuildFire::IsDone()
{
	return bBuiltFire;
}

bool UBuildFire::RequiresInRange()
{
	return true;
}

bool UBuildFire::CheckProceduralPrecondition(AActor* Agent)
{
	return SetDestinationActorToTargetClass(Agent, AFirepit::StaticClass());
}

bool UBuildFire::Perform(AActor* Agent, float Deltatime)
{
	if (Progress < WorkDuration)
	{
		Progress += Deltatime;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Building Fire")));
	}
	else
	{
		//Action Complete
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Fire Built")));
		bBuiltFire = true;
		if (AFirepit* fire = Cast<AFirepit>(TargetObject))
		{
			fire->bBurning = bBuiltFire;
		}
	}

	return true;
}
