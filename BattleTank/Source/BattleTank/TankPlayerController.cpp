// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController has NO ControlledTank!!!"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController has ControlledTank: %s"), *(ControlledTank->GetName()))
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
	if (!GetControlledTank()) {
		return;
	}
	// get world location if line trace through crosshair
	// if it hits landscape
		// tell controlled tank to aim at this point
}

