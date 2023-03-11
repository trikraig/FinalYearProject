// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionPlanner.h"
#include "../Interface/NeedsSystem.h"
#include "../Interface/Provider.h"
#include "Kismet/GameplayStatics.h"
#include "../Interface/Producer.h"
#include "../Interface/Processor.h"

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

void UActionPlanner::PlanActions(const FNeed& TargetNeed)
{
	//Find stations in that world that meet the TargetNeed.
	TArray<AActor*> FoundStations;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStation::StaticClass(), FoundStations);

	for (AActor* StationActor : FoundStations)
	{
		//All stations that provide needs are Providers.
		if (AProvider* Provider = Cast<AProvider>(StationActor))
		{
			//Check if Producer output Need matches target Need
			if (Provider->OutputNeedType == TargetNeed.Type)
			{
				if (Provider->RequirementsMet())
				{
					CreateAction(Provider);
				}
				else
				{
					PlanActions(FoundStations, Provider);			
				}
			}
		}
	}
}

void UActionPlanner::PlanActions(TArray<AActor*> FoundStations,  AProvider* RequiredProvider)
{
	//Create Actions to fulfill this Providers Requirements.
	for (AActor* StationActor : FoundStations)
	{
		if (StationActor == RequiredProvider) continue;

		AStation* FoundStation = nullptr;

		//if producer or processor, check output resource type if matches required resource type.
		if (AProducer* Producer = Cast<AProducer>(StationActor))
		{
			if (Producer->OutputResourceType == RequiredProvider->InputResourceType)
				FoundStation = Producer;
		}
		else if (AProcessor* Processor = Cast<AProcessor>(StationActor))
		{
			if (Processor->OutputResourceType == RequiredProvider->InputResourceType)
				FoundStation = Processor;
		}

		//TODO - Can be move into else if above.
		if (FoundStation)
		{
			if (FoundStation->RequirementsMet())
			{
				CreateAction(FoundStation);
			}
			else if (AProcessor* Processor = Cast<AProcessor>(FoundStation))
			{
				//Plan Actions
				PlanActions(FoundStations, Processor);
			}
		}

		//Station not valid, continue.
	}
}

void UActionPlanner::PlanActions(TArray<AActor*> FoundStations, AProcessor* RequiredProcessor)
{
	//We could potentially have raw resources needed going through two processors to get final resource.

	//Create Actions to fulfill this Providers Requirements.
	for (AActor* StationActor : FoundStations)
	{
		if (StationActor == RequiredProcessor) continue;

		AStation* FoundStation = nullptr;

		//if producer or processor, check output resource type if matches required resource type.
		if (AProducer* Producer = Cast<AProducer>(StationActor))
		{
			if (Producer->OutputResourceType == RequiredProcessor->InputResource)
				FoundStation = Producer;
		}
		else if (AProcessor* Processor = Cast<AProcessor>(StationActor))
		{
			if (Processor->OutputResourceType == RequiredProcessor->InputResource)
				FoundStation = Processor;
		}

		if (FoundStation)
		{
			if (FoundStation->RequirementsMet())
			{
				CreateAction(FoundStation);
			}
			else if (AProcessor* Processor = Cast<AProcessor>(FoundStation))
			{
				//Plan Actions
				PlanActions(FoundStations, Processor);
			}
		}

		//Station not valid, continue.
	}
}

void UActionPlanner::CreateAction(AActor* TargetStation)
{
	//Create Action with this Provider as the target.
	Action NewAction;
	NewAction.DestinationActor = TargetStation;
	//TODO - Generate Cost.
	//TODO - CACHE CONDITION THAT NEEDS TO BE MET TO CLEAR ACTION.
	Actions.Add(NewAction);
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
				PlanActions(Need.Value);
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
