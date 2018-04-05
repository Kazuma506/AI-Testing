// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BreadVendorAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ABreadVendorAIController : public AAIController
{
	GENERATED_BODY()
public:
	ABreadVendorAIController();

	virtual void Possess(APawn *InPawn) override;
	void Tick(float DeltaTime);
	void MoveToStand();
	void MoveHome();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);
	void VillagerBehavior();

	bool atStand;
	bool atHome;

	bool destination1;
	bool destination2;

	bool hasRotated;

	float timeAtStand;
	float timeAtHome;

	FTimerHandle positionSwitchingHandle;

	const FVector standLocation = FVector(5980.0, -770.0, 1260.0); // Stand Location
	const FVector homeLocation = FVector(4210.0, 1840.0, 1260.0); // Home Location
};
