// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GeneralGoodsOwnerAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AGeneralGoodsOwnerAIController : public AAIController
{
	GENERATED_BODY()
public:
	AGeneralGoodsOwnerAIController();

	virtual void Possess(APawn *InPawn) override;
	void Tick(float DeltaTime);
	void MoveToCounter();
	void MoveToShelfUnit1();
	void MoveToShelfUnit2();
	void MoveToChair();
	void MoveToShelfUnit3();
	void MoveToShelfUnit4();
	void MoveToBed();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atCounter;
	bool atShelfUnit1;
	bool atShelfUnit2;
	bool atChair;
	bool atShelfUnit3;
	bool atShelfUnit4;
	bool atBed;

	bool rotatedAtCounter;
	bool rotatedAtShelfUnit1;
	bool rotatedAtShelfUnit2;
	bool rotatedAtChair;
	bool rotatedAtShelfUnit3;
	bool rotatedAtShelfUnit4;
	bool rotatedAtBed;

	bool destination1;
	bool destination2;
	bool destination3;
	bool destination4;
	bool destination5;
	bool destination6;
	bool destination7;

	float timeAtCounter;
	float timeAtShelfUnit1;
	float timeAtShelfUnit2;
	float timeAtChair;
	float timeAtShelfUnit3;
	float timeAtShelfUnit4;
	float timeAtBed;

	FTimerHandle positionSwitchingHandle;

	const FVector counterLocation = FVector(5350, 1180, 1260.0); // Counter Location
	const FVector shelfUnit1Location = FVector(4780.0, 790.0, 1260.0); // Shelf Unit 1 Location
	const FVector shelfUnit2Location = FVector(5020.0, 620.0, 1260.0); // Shelf Unit 2 Location
	const FVector chairLocation = FVector(5600.0, 1230.0, 1260.0); // Chair Location
	const FVector shelfUnit3Location = FVector(5640.0, 630.0, 1260.0); // Shelf Unit 3 Location
	const FVector shelfUnit4Location = FVector(5880.0, 760.0, 1260.0); // Shelf Unit 4 Location
	const FVector bedLocation = FVector(5880.0, 1200.0, 1260.0); // Bed Location
};
