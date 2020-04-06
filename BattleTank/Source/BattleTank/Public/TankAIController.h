// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TankAIController.generated.h"

// Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
private:
	virtual void BeginPlay() override;

	void AimTowardsPlayer(); // obsolete. remove

	// How close AI tank will get to the player before it stops moving towards him
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 3000.0f;

	ATank* ControlledTank = nullptr;
};
