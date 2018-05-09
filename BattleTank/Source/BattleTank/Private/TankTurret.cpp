// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	// Move the turret the right amount in this direction for this frame
	auto RotationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));
}
