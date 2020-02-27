// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "TankPlayerController.generated.h"

// Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	// Start moving the barrel so that the shot hit where
	// crosshair intersects with the world
	void AimTowardsCrosshair();

	// Return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation{ 0.5f };

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation{ 0.333333f };

	UPROPERTY(EditAnywhere)
	float LineTraceRange{ 1000000.0f };
};
