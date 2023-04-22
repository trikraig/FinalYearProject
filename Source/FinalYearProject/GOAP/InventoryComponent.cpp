// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UInventoryComponent::AddItem(AActor* Actor)
{
	Items.Add(Actor);
}

void UInventoryComponent::RemoveItem(AActor* Actor)
{
	Items.Remove(Actor);
}

AActor* UInventoryComponent::FindItemWithTag(const FName& Tag)
{
	if (Items.Num() > 0)
	{
		return *Items.FindByPredicate([Tag](AActor* Item)
			{
				return Item->Tags.Contains(Tag);
			});
	}

	return nullptr;
}

