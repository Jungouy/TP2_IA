// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/MacPan.h"

#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Public/TP_SuperCoolLeft.h"
#include "Public/TP_SuperCoolRight.h"
#include "Public/WorldData.h"
#include "Runtime/MovieSceneTracks/Private/MovieSceneTracksCustomAccessors.h"


// Sets default values
AMacPan::AMacPan()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(BoxCollision);


	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent0"));
	MovementComponent->UpdatedComponent = BoxCollision;
	bIsTeleporting = false;
}

// Called when the game starts or when spawned
void AMacPan::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMacPan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetActorRotation()!=FRotator::ZeroRotator)
	{
		SetActorRotation(FRotator::ZeroRotator);
	}
}

void AMacPan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent)
	PlayerInputComponent->BindAxis(TEXT("MoveUpDown"), this, &AMacPan::MoveUpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveRightLeft"), this, &AMacPan::MoveRightLeft);
}

void AMacPan::MoveUpDown(float Value)
{
	if (MovementComponent  && FMath::Abs(Value) > KINDA_SMALL_NUMBER)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AMacPan::MoveRightLeft(float Value)
{
	if (MovementComponent && FMath::Abs(Value) > KINDA_SMALL_NUMBER)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}
void AMacPan::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (bIsTeleporting)
		return; // on ignore les overlaps pendant la période de cooldown

	if (OtherActor && OtherActor != this)
	{
		if (OtherActor->IsA(ATP_SuperCoolLeft::StaticClass()))
		{
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Overlaped by Left"));
			bIsTeleporting = true;
			SetActorLocation(FVector(50.f, 2080.f, 150.f), false, nullptr, ETeleportType::TeleportPhysics);
			MovementComponent->Velocity = FVector::ZeroVector;
			// démarre un timer pour réactiver les overlaps après 0.25s (ajuste la durée si besoin)
			GetWorldTimerManager().SetTimer(TeleportCooldownTimer, this, &AMacPan::ResetTeleportFlag, 0.25f, false);
		}
		else if (OtherActor->IsA(ATP_SuperCoolRight::StaticClass()))
		{
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Overlaped by Right"));
			bIsTeleporting = true;
			SetActorLocation(FVector(50.f, -2080.f, 150.f),false, nullptr, ETeleportType::TeleportPhysics);
			MovementComponent->Velocity = FVector::ZeroVector;
			GetWorldTimerManager().SetTimer(TeleportCooldownTimer, this, &AMacPan::ResetTeleportFlag, 0.25f, false);
		}
	}
}

void AMacPan::ResetTeleportFlag()
{
	bIsTeleporting = false;
}


