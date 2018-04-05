// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AtHomeHouseSevenAIController.generated.h"

/**
 *  
 */
UCLASS()
class AITESTING_API AAtHomeHouseSevenAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AAtHomeHouseSevenAIController();

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

	const FVector fireLocation = FVector(6950.0, 3380.0, 1260.0); // Fire Location
	const FVector pantryLocation = FVector(6760.0, 3140.0, 1260.0); // Pantry Location
	const FVector chairLocation = FVector(6800.0, 3530.0, 1260.0); // Chair Location
	const FVector outsideLocation = FVector(6840.0, 2920.0, 1260.0); // Outside Location
	const FVector bedLocation = FVector(7090.0, 3590.0, 1260.0); // Bed Location
};
