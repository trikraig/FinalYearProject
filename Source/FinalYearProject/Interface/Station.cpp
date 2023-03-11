// Fill out your copyright notice in the Description page of Project Settings.


#include "Station.h"
#include "Components/CapsuleComponent.h"
#include "FinalYearProject/Characters/Agent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AStation::AStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// declare trigger capsule
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	// declare overlap events
	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AStation::BeginPlay()
{
	Super::BeginPlay();

	AActor* FoundResourceManager = UGameplayStatics::GetActorOfClass(GetWorld(), AResourceManager::StaticClass());
	if (FoundResourceManager)
		ResourceManager = Cast<AResourceManager>(FoundResourceManager);
}

// Called every frame
void AStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RequirementsMet() && Workers.Num() > 0)
	{
		//Check Progress
		if (fProgress > 100)
		{
			OnProgressCompletion();
		}
		else
		{
			//Increase progress to completion by progress rate X num workers.
			fProgress += (fProgressRate * Workers.Num());
		}
	}

}

void AStation::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (Cast<AAgent>(OtherActor))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
			AddWorker(OtherActor);
		}
	}
}

void AStation::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (Cast<AAgent>(OtherActor))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
			RemoveWorker(OtherActor);
		}
	}
}

void AStation::AddWorker(AActor* Worker)
{
	Workers.Add(Worker);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Worker %s loaded into Station: %s"), *Worker->GetName(), *this->GetName()));

}

void AStation::RemoveWorker(AActor* Worker)
{
	Workers.Remove(Worker);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Worker %s unloaded from Station: %s"), *Worker->GetName(), *this->GetName()));

}

void AStation::OnProgressCompletion()
{
	//Reset Station (clear active progress)
	Reset();

	//Derived will have output resources etc.
}

void AStation::Reset()
{
	//Reset progress value.
	fProgress = 0.0f;
}

bool AStation::RequirementsMet()
{
	//Any base requirements for stations.
	return true;
}

