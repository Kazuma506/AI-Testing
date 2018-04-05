// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DayTimeCrowd3AIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ADayTimeCrowd3AIController : public AAIController
{
	GENERATED_BODY()
public:
	ADayTimeCrowd3AIController();
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

	const FVector standLocation = FVector(4350.0, 1450.0, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(9550.0, 1740.0, 1260.0); // Home Location
};