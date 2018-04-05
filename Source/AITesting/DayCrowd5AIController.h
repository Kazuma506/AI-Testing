// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DayCrowd5AIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ADayCrowd5AIController : public AAIController
{
	GENERATED_BODY()
public:
	ADayCrowd5AIController();

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

	const FVector standLocation = FVector(4206, 1033.0, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(9510.0, 3600.0, 1260.0); // Home Location
};
