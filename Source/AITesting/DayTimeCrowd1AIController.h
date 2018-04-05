// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DayTimeCrowd1AIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ADayTimeCrowd1AIController : public AAIController
{
	GENERATED_BODY()
public:
	ADayTimeCrowd1AIController();

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

	const FVector standLocation = FVector(4500.0, 1440.0, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(8040.0, 1150.0, 1260.0); // Home Location
};
