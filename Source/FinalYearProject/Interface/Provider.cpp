// Fill out your copyright notice in the Description page of Project Settings.


#include "Provider.h"
#include "FinalYearProject/Characters/Agent.h"

bool AProvider::RequirementsMet()
{
	bool bResult = Super::RequirementsMet();

	//Check if valid input resource.
	if (bResult)
	{
		bResult = InputResourceQuantity > RequiredInputQuantity;
	}

	return bResult;
}

void AProvider::OnProgressCompletion()
{
	Super::OnProgressCompletion();

	//Add resulting need increases to the workers

	for (AActor* Actor : Workers)
	{
		if (AAgent* Agent = Cast<AAgent>(Actor))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Worker: %s has need fufilled"), *Agent->GetName()));

			if (Agent->NeedsSystemComponent)
			{
				Agent->NeedsSystemComponent->FufillNeed(OutputNeed, NeedFufillmentAmount);
			}
		}
	}
}

