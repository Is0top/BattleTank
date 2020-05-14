// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("AI controller begin play"));
	ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI could not posess a tank"));
	}

	//ATank* PlayerTank = GetPlayerTank();
	//if (PlayerTank)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AI found player tank: %s"), *PlayerTank->GetName());
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AI could not find a player tank"));
	//}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
	//AimTowardsPlayer();
	
}

void ATankAIController::AimTowardsPlayer()
{
	/*if (!ControlledTank) { return; }
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("AI could not find a player tank")); 
		return;
	}
	
	ControlledTank->AimAt(PlayerTank->GetActorLocation());*/
}
