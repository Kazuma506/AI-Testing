// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DayCrowd6AIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ADayCrowd6AIController : public AAIController
{
	GENERATED_BODY()
public:
	ADayCrowd6AIController();

	virtual void Possess(APawn *InPawn) override;
	void Tick(float DeltaTime);
	void MoveToCrowd();
	void MoveHome();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atCrowd;
	bool atHome;

	bool hasRotated;

	bool destination1;
	bool destination2;

	float timeAtCrowd;
	float timeAtHome;

	FTimerHandle positionSwitchingHandle;

	const FVector standLocation = FVector(4120.0, 924.0, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(7780.0, 3530.0, 1260.0); // Home Location
};

