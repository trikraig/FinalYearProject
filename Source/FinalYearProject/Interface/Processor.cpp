// Fill out your copyright notice in the Description page of Project Settings.

#include "Processor.h"

bool AProcessor::RequirementsMet()
{
	bool bResult = Super::RequirementsMet();

	if (bResult)
	{
		bResult = ResourceManager && ResourceManager->ResourceAvailable(InputResource, InputQuantity);
	}

	return bResult;
}

void AProcessor::OnProgressCompletion()
{
	Super::OnProgressCompletion();

	//Add copy of generated resource to Resource Manager.
	if (ResourceManager)
	{
		//Remove input resources.
		ResourceManager->AddResource(InputResource, -InputQuantity);
		//Add output resources.
		ResourceManager->AddResource(OutputResource, OutputQuantity);
	}
}

