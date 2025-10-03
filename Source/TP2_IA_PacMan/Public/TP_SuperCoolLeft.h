// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TP_SuperCoolLeft.generated.h"

UCLASS()
class TP2_IA_PACMAN_API ATP_SuperCoolLeft : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATP_SuperCoolLeft();
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollision;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
