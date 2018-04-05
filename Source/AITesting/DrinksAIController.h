// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DrinksAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ADrinksAIController : public AAIController
{
	GENERATED_BODY()
public:
	ADrinksAIController();

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

	const FVector standLocation = FVector(7260, -1190.0, 1260.0); // Stand Location
	const FVector homeLocation = FVector(9540.0, 2660.0, 1260.0); // Home Location
};
