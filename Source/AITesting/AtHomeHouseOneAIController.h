// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AtHomeHouseOneAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AAtHomeHouseOneAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AAtHomeHouseOneAIController();

	virtual void Possess(APawn *InPawn) override;

	void Tick(float DeltaTime);

	void MoveToFire();

	void MoveToPantry();

	void MoveToChair();

	void MoveOutside();

	void MoveToBed();

	void VillagerBehavior();

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atFire;
	bool atPantry;
	bool atChair;
	bool outstide;
	bool atBed;

	bool rotatedAtFire;
	bool rotatedAtPantry;
	bool rotatedAtChair;
	bool rotatedOutside;
	bool rotatedAtBed;

	bool destination1;
	bool destination2;
	bool destination3;
	bool destination4;
	bool destination5;

	float timeAtFire;
	float timeAtPantry;
	float timeAtChair;
	float timeOutside;
	float timeAtBed;

	FTimerHandle positionSwitchingHandle;

	const FVector fireLocation = FVector(7870.0, 980.0, 1260.0); // Fire Location
	const FVector pantryLocation = FVector(7690.0, 860.0, 1260.0); // Pantry Location
	const FVector chairLocation = FVector(7730.0, 1170.0, 1260.0); // Chair Location
	const FVector outsideLocation = FVector(7830.0, 410.0, 1260.0); // Outside Location
	const FVector bedLocation = FVector(8010.0, 1240.0, 1260.0); // Bed Location
};
