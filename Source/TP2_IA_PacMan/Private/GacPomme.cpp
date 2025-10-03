// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/GacPomme.h"

#include "Components/BoxComponent.h"
#include "Public/MacPan.h"
#include "Public/WorldData.h"


// Sets default values
AGacPomme::AGacPomme()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(BoxCollision);
}

// Called when the game starts or when spawned
void AGacPomme::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGacPomme::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGacPomme::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Overlaped"));

	if (OtherActor && OtherActor != this)
	{
		if  (OtherActor && OtherActor->IsA(AMacPan::StaticClass()))
		{
			
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Overlaped by our ManPan"));
			AWorldData::Score += 100;
			Destroy();
		}
	}
}

