// Copyright Yuri Khromov 
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TankAIController.generated.h"

// Forward declarations

class UTankAimingComponent;

/**
 * Responsible for AI Tank aiming
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

protected:
	// How close AI tank will get to the player before it stops moving towards him
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 6000.0f;
private:
	virtual void BeginPlay() override;
};
