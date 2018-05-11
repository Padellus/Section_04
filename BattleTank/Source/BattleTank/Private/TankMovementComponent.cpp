// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankMovementComponent.h"
#include "Public/TankTrack.h"


void UTankMovementComponent::Intialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (LeftTrackToSet) {
		LeftTrack = LeftTrackToSet;
	}
	if (RightTrackToSet) {
		RightTrack = RightTrackToSet;
	}
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("IntendMoveForward Throw: %f"), Throw);
	if (LeftTrack) {
		LeftTrack->SetThrottle(Throw);
	}
	if (RightTrack) {
		RightTrack->SetThrottle(Throw);
	}
	// TODO prevent double speed
}

