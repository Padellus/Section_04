// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankMovementComponent.h"
#include "Public/TankTrack.h"


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);
}

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
	if (LeftTrack) {
		LeftTrack->SetThrottle(Throw);
	}
	if (RightTrack) {
		RightTrack->SetThrottle(Throw);
	}
	// TODO prevent double speed
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (LeftTrack) {
		LeftTrack->SetThrottle(Throw);
	}
	if (RightTrack) {
		RightTrack->SetThrottle(-Throw);
	}
	// TODO prevent double speed
}

