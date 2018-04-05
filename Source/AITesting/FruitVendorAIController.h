// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FruitVendorAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AFruitVendorAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AFruitVendorAIController();

	virtual void Possess(APawn *InPawn) override;
	void Tick(float DeltaTime);
	void MoveToStand();
	void MoveHome();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atStand;
	bool atHome;

	bool hasRotated;

	bool destination1;
	bool destination2;

	float timeAtStand;
	float timeAtHome;

	FTimerHandle positionSwitchingHandle;

	const FVector standLocation = FVector(6120.0, -1250.0, 1260.0); // Stand Location
	const FVector homeLocation = FVector(6210.0, 3620.0, 1260.0); // Home Location
};

