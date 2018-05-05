// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController has NO ControlledTank!!!"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController has ControlledTank: %s"), *(ControlledTank->GetName()))
	}

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController found NO PlayerTank!!!"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found PlayerTank: %s"), *(PlayerTank->GetName()))
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
