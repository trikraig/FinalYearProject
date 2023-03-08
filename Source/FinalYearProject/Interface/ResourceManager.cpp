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

void AResourceManager::AddResource(EResourceType Type, int Quantity)
{
	//TODO - Change the TArray to something easier to insert into.

	for (Resource* ThisResource : Resources)
	{
		if (ThisResource->Type == Type)
			ThisResource->Quantity += Quantity;
	}
}

bool AResourceManager::ResourceAvailable(EResourceType Type, int Quantity) const
{
	//TODO - Change the TArray to something easier to check
	for (Resource* ThisResource : Resources)
	{
		if (ThisResource->Type == Type)
			return ThisResource->Quantity >= Quantity;
	}

	return false;
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
		NewResource->Quantity = 10;
		NewResource->Type = ResourceType; // static_cast<uint8> (ResourceType);
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

