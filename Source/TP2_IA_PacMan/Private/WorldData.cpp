// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/WorldData.h"


int AWorldData::Score = 0;
// Sets default values
AWorldData::AWorldData()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWorldData::BeginPlay()
{
	Super::BeginPlay();
	Score = 0;
}

// Called every frame
void AWorldData::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
int AWorldData::GetScore() const
{
	return Score;
}

