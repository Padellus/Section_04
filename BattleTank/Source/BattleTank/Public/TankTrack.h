// Copyright Phillip Patti.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	// Max forcer per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float MaxDrivingForce = 400000;

private:
	UTankTrack();

	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	void DriveTrack();

	float CurrentThrottle;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
