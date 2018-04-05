// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TrinketsVendorAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ATrinketsVendorAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATrinketsVendorAIController();

	virtual void Possess(APawn *InPawn) override;

	void Tick(float DeltaTime);

	void MoveToStand();

	void MoveHome();

	void VillagerBehavior();

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool AtStand;
	bool AtHome;

	bool destination1;
	bool destination2;

	bool HasRotated;

	float TimeAtStand;
	float TimeAtHome;

	FTimerHandle PositionSwitchingHandle;

	const FVector StandLocation = FVector(7360.0, -760.0, 1260.0); // Stand Location
	const FVector HomeLocation = FVector(5350.0, 3600.0, 1260.0); // Home Location
};
