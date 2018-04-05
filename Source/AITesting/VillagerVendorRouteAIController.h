// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "VillagerVendorRouteAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AVillagerVendorRouteAIController : public AAIController
{
	GENERATED_BODY()

public: 
	AVillagerVendorRouteAIController();

	virtual void Possess(class APawn* InPawn) override;
	virtual void Tick(float DeltaSeconds) override;
	void MoveToBreadVendor();
	void MoveToFruitVendor();
	void MoveToMeatVendor();
	void MoveToVegetableVendor();
	void MoveToDrinksVendor();
	void MoveToPantry();
	void MoveToHouseTen();
	void MoveToBed();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atBreadVendor;
	bool atFruitVendor;
	bool atMeatVendor;
	bool atVegetableVendor;
	bool atDrinksVendor;
	bool atPantry;
	bool atHouseTen;
	bool atBed;

	bool rotatedAtBreadVendor;
	bool rotatedAtFruitVendor;
	bool rotatedAtMeatVendor;
	bool rotatedAtVegetableVendor;
	bool rotatedAtDrinksVendor;
	bool rotatedAtPantry;
	bool rotatedAtHouseTen;
	bool rotatedAtBed;

	bool destination1;
	bool destination2;
	bool destination3;
	bool destination4;
	bool destination5;
	bool destination6;
	bool destination7;
	bool destination8;

	float acceptanceRadius;

	float waitTime1;
	float waitTime2;
	float waitTime3;
	float waitTime4;
	float waitTime5;
	float waitTime6;
	float waitTime7;
	float waitTime8;

	FTimerHandle waitTimerHandle;

	const FVector breadVendorLocation = FVector(6290.0, -720.0, 1260.0); // Bread vendon
	const FVector fruitVendorLocation = FVector(6350.0, -1120.0, 1260.0); // Fruit Vendor
	const FVector meatVendorLocation = FVector(6560.0, -1330, 1260.0); // Meat Vendor
	const FVector vegetableVendorLocation = FVector(6770.0, -1250.0, 1260.0); // Vegetable Vendor
	const FVector drinksVendorLocation = FVector(6960.0, -1080.0, 1260.0); // Drinks Vendor
	const FVector pantryLocation = FVector(9150.0, 1170.0, 1260.0); // Home (Pantry) House 2
	const FVector houseTenLocation = FVector(4290.0, 3370.0, 1260.0); // Visit House 10
	const FVector bedLocation = FVector(9560, 830.0, 1260.0); // Home (Bed) House 2
};
