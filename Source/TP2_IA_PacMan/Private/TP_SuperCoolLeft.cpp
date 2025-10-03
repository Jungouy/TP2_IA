// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TP_SuperCoolLeft.h"

#include "Components/BoxComponent.h"


// Sets default values
ATP_SuperCoolLeft::ATP_SuperCoolLeft()
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
void ATP_SuperCoolLeft::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATP_SuperCoolLeft::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

