// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AlchemyStoreOwnerAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AAlchemyStoreOwnerAIController : public AAIController
{
	GENERATED_BODY()
public:
	AAlchemyStoreOwnerAIController();

	virtual void Possess(APawn *InPawn) override;
	void Tick(float DeltaTime);
	void MoveToTable(); 
	void MoveToAlchemyPot(); 
	void MoveToChair();
	void MoveToPotionShelf();
	void MoveToBed();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atTable; 
	bool atAlchemyPot;
	bool atChair;
	bool atPotionShelf;
	bool atBed;

	bool rotatedAtTable;
	bool rotatedAtAlchemyPot;
	bool rotatedAtChair;
	bool rotatedAtPotionShelf;
	bool rotatedAtBed;

	bool destination1;
	bool destination2;
	bool destination3;
	bool destination4;
	bool destination5;
	bool destination6;
	bool destination7;

	float timeAtTable;
	float timeAtAlchemyPot;
	float timeAtChair;
	float timeAtPotionShelf;
	float timeAtBed;

	FTimerHandle positionSwitchingHandle;

	const FVector tableLocation = FVector(2808.0, 1037.0, 1260.0); // Table Location
	const FVector alchemyPotLocation = FVector(2614.0, 993.0, 1260.0); // Alchemy Pot Location
	const FVector chairLocation = FVector(2516.0, 870.0, 1260.0); // Chair Location
	const FVector potionShelfLocation = FVector(2969.0, 1235.0, 1260.0); // Table Section 4 Location
	const FVector bedLocation = FVector(2518.0, 617.0, 1260.0); // Bed Location
};
