// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MacPan.generated.h"

UCLASS()
class TP2_IA_PACMAN_API AMacPan : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMacPan();
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollision;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPawnMovementComponent* MovementComponent;

	void MoveUpDown(float Value);
	void MoveRightLeft(float Value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// dans public ou protected
	bool bIsTeleporting;
	FTimerHandle TeleportCooldownTimer;

	UFUNCTION()
	void ResetTeleportFlag();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
