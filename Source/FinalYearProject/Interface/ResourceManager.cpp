// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceManager.h"


// Sets default values
AResourceManager::AResourceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AResourceManager::~AResourceManager()
{
	for (Resource* ThisResource : Resources)
	{
		delete ThisResource;
	}
}

FString AResourceManager::GetName(EResourceType Type)
{
	switch(Type)
	{
	case EResourceType::RawFood: return FString("Raw Food"); break;
	case EResourceType::Ingredients: return FString("Ingredients"); break;
	case EResourceType::Food: return FString("Food"); break;
	}

	return FString();
}

// Called when the game starts or when spawned
void AResourceManager::BeginPlay()
{
	Super::BeginPlay();

	for (EResourceType ResourceType : TEnumRange<EResourceType>())
	{
		//Add to Resources array.
		Resource* NewResource = new Resource;
		NewResource->Name = GetName(ResourceType);
		NewResource->Quantity = 0;
		NewResource->Type = static_cast<uint8> (ResourceType);
		Resources.Add(NewResource);
	}
	
}

void AResourceManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	for (Resource* ThisResource : Resources)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Resource: %s, Value: %i"), *ThisResource->Name, ThisResource->Quantity));
	}


}

