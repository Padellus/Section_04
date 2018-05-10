// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	// TODO Clamp actual throttle
	auto ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

