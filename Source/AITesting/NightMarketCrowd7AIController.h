// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NightMarketCrowd7AIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ANightMarketCrowd7AIController : public AAIController
{
	GENERATED_BODY()
public:
	ANightMarketCrowd7AIController();

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

	const FVector crowdLocation = FVector(6656.0, -807.0, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(7760.0, 3550.0, 1260.0); // Home Location		
};

