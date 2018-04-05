// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NightMarketCrowd6AIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ANightMarketCrowd6AIController : public AAIController
{
	GENERATED_BODY()
public:
	ANightMarketCrowd6AIController();

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

	const FVector crowdLocation = FVector(6751.0, -919, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(6220.0, 3637.0, 1260.0); // Home Location		
};
