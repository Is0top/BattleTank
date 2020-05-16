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
private:
	virtual void BeginPlay() override;

	// How close AI tank will get to the player before it stops moving towards him
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 3000.0f;


};
