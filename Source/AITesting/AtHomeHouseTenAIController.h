// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AtHomeHouseTenAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AAtHomeHouseTenAIController : public AAIController
{
	GENERATED_BODY()

public:
	AAtHomeHouseTenAIController();

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

	const FVector fireLocation = FVector(4310.0, 3380.0, 1260.0); // Fire Location
	const FVector pantryLocation = FVector(4100.0, 3230.0, 1260.0); // Pantry Location
	const FVector chairLocation = FVector(4140, 3520.0, 1260.0); // Chair Location
	const FVector outsideLocation = FVector(4380.0, 2930.0, 1260.0); // Outside Location
	const FVector bedLocation = FVector(4400.0, 3570.0, 1260.0); // Bed Location
};
