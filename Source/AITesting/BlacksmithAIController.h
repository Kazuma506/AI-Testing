// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BlacksmithAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ABlacksmithAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABlacksmithAIController();

	virtual void Possess(APawn *InPawn) override;

	void Tick(float DeltaTime);

	void MoveToForge();
	void MoveToAnvil();
	void MoveToChair();
	void MoveToBed();
	void MoveToBreakSpot();
	void BlacksmithBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atForge; 
	bool atAnvil;
	bool atChair;
	bool atBed;
	bool atBreakSpot;

	bool rotatedAtAnvil;
	bool rotatedAtBreakSpot;

	bool destination1;
	bool destination2;
	bool destination3;
	bool destination4;
	bool destination5;

	float timeAtAnvil;
	float timeAtForge;
	float timeAtChair;
	float timeAtBed;
	float timeAtBreakSpot;

	FTimerHandle positionSwitchingHandle;

	const FVector anvilLocation = FVector(5370, -810, 1260);
	const FVector forgeLocation = FVector(5480, -810, 1260);
	const FVector chairLocation = FVector(4970, -1420, 1260);
	const FVector bedLocation = FVector(4860, -1590, 1260);
	const FVector breakSpotLocation = FVector(5090, -700, 1260);
};
