// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player controller begin play"));
	ATank* posessedTank = GetControlledTank();
	if (posessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *posessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank posessed"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // out parameter
	// Get world position if linetrace through crosshair
	// If it hits the landscape
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0f);
	return true;
}