// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("AI controller begin play"));
	//ATank* posessedTank = GetControlledTank();
	//if (posessedTank)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AI posesses: %s"), *posessedTank->GetName());
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("No AI tank posessed"));
	//}

	ATank* playerTank = GetPlayerTank();
	if (playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found player tank: %s"), *playerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI could not find a player tank"));
	}

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}