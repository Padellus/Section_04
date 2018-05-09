// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	// Move the barrel the right amount in this direction for this frame
	auto ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
