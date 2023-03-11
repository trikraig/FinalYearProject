// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionPlanner.h"
#include "../Interface/NeedsSystem.h"
#include "../Interface/Provider.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UActionPlanner::UActionPlanner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActionPlanner::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void UActionPlanner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UActionPlanner::CreateActions(const FNeed& TargetNeed)
{
	//Find stations in that world that meet the TargetNeed.
	TArray<AActor*> FoundStations;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AProvider::StaticClass(), FoundStations);

	for (AActor* StationActor : FoundStations)
	{
		if (AProvider* Provider = Cast<AProvider>(StationActor))
		{
			//Check if Producer output Need matches target Need
			if (Provider->OutputNeedType == TargetNeed.Type)
			{
				if (Provider->RequirementsMet())
				{
					//Create Action with this Provider as the target.
					Action NewAction;
					NewAction.DestinationActor = Provider;
					Actions.Add(NewAction);
				}
				else
				{
					//Create Actions to fulfill this Providers Requirements.
					CreateActions(Provider);
				}
			}
		}
	}
}

void UActionPlanner::CreateActions(AStation* TargetStation)
{
	//TODO
}

bool UActionPlanner::FindNewAction(AAgent* Agent)
{
	Actions.Empty();

	// Create actions from Needs.
	if (UNeedsSystem* Needs = Agent->NeedsSystemComponent)
	{
		for (auto& Need : Needs->NeedsMap)
		{
			if (Need.Value.IsDiscontent())
			{
				CreateActions(Need.Value);
			}
		}
	}

	//Select action. - TODO

	if (Actions.Num() > 0)
	{
		Agent->CurrentAction = &Actions[0];
	}

	return false;
}
