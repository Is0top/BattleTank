// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Holds Barrels properties and Elevate method
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is downward movement and +1 is upward movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, category = Setup)
	float MaxDegreesPerSecond = 10.0f;

	UPROPERTY(EditDefaultsOnly, category = Setup)
	float MinElevationDegrees = 0.0f; 

	UPROPERTY(EditDefaultsOnly, category = Setup)
	float MaxElevationDegrees = 30.0f; 
};
