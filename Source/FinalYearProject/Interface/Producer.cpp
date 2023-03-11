// Fill out your copyright notice in the Description page of Project Settings.


#include "Producer.h"

void AProducer::OnProgressCompletion()
{
	Super::OnProgressCompletion();

	//Add copy of generated resource to Resource Manager.
	if (ResourceManager)
	{
		ResourceManager->AddResource(OutputResourceType, Quantity);
	}
}
