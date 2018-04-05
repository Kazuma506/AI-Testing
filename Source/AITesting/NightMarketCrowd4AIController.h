// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NightMarketCrowd4AIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ANightMarketCrowd4AIController : public AAIController
{
	GENERATED_BODY()
public:
	ANightMarketCrowd4AIController();

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

	const FVector crowdLocation = FVector(6571, -949.0, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(7770.0, 2180.0, 1260.0); // Home Location	
};
