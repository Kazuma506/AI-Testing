// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "VegatableAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AVegatableAIController : public AAIController
{
	GENERATED_BODY()
public:
	AVegatableAIController();

	virtual void Possess(APawn *InPawn) override;

	void Tick(float DeltaTime);

	void MoveToStand();
	void MoveHome();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atStand;
	bool atHome;

	bool destination1;
	bool destination2;

	bool hasRotated;

	float timeAtStand;
	float timeAtHome;

	FTimerHandle positionSwitchingHandle;

	const FVector standLocation = FVector(6920.0, -1490.0, 1260.0); // Stand Location
	const FVector homeLocation = FVector(5060.0, 1800.0, 1260.0); // Home Location
};
