// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NightLakeCrowd2AIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ANightLakeCrowd2AIController : public AAIController
{
	GENERATED_BODY()
public:
	ANightLakeCrowd2AIController();

	virtual void Possess(APawn *InPawn) override;
	void Tick(float DeltaTime);
	void MoveToCrowd();
	void MoveHome();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atCrowd;
	bool atHome;

	bool rotateAtLake;
	bool rotateAtBed;

	bool destination1;
	bool destination2;

	float timeAtCrowd;
	float timeAtHome;

	FTimerHandle positionSwitchingHandle;

	const FVector standLocation = FVector(9013.0, -452.0, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(5040.0, 1870.0, 1260.0); // Home Location
};
