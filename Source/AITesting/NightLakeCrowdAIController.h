// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NightLakeCrowdAIController.generated.h"

UCLASS()
class AITESTING_API ANightLakeCrowdAIController : public AAIController
{
	GENERATED_BODY()
public:
	ANightLakeCrowdAIController();

	virtual void Possess(APawn *InPawn) override;
	void Tick(float DeltaTime);
	void MoveToCrowd();
	void MoveHome();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atCrowd;
	bool atHome;

	bool rotateAtLake;
	bool rotateAtBed;

	bool destination1;
	bool destination2;

	float timeAtCrowd;
	float timeAtHome;

	FTimerHandle positionSwitchingHandle;

	const FVector standLocation = FVector(8940, -430.0, 1260.0); // Crowd Location
	const FVector homeLocation = FVector(4240.0, 1826.0, 1260.0); // Home Location
};

