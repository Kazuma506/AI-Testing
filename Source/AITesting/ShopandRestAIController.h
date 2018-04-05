// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShopandRestAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AShopandRestAIController : public AAIController
{
	GENERATED_BODY()

public:
	AShopandRestAIController();

	virtual void Possess(class APawn* InPawn) override;
	virtual void Tick(float DeltaSeconds) override;
	void MoveToVegetableVendor();
	void MoveToDrinksVendor();
	void MoveToGeneralGoodsStore();
	void MoveToRestSpot();
	void MoveToMeetSpot();
	void MoveToBed();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atVegetableVendor;
	bool atDrinksVendor;
	bool atGeneralGoodsStore;
	bool atRestSpot;
	bool atMeetSpot;
	bool atBed;

	bool rotateAtVegetableVendor;
	bool rotatAtDrinksVendor;
	bool rotateAtGeneralGoodsStore;
	bool rotateAtRestSpot;
	bool rotateAtMeetSpot;
	bool rotateAtBed;

	bool destination1;
	bool destination2;
	bool destination3;
	bool destination4;
	bool destination5;
	bool destination6;

	float waitTime1;
	float waitTime2;
	float waitTime3;
	float waitTime4;
	float waitTime5;
	float waitTime6;
	float waitTime7;
	float waitTime8;

	FTimerHandle waitTimerHandle;

	const FVector vegeatableVendorLocation = FVector(6780.0, -1240.0, 1260.0); // Vegatable Vendor
	const FVector drinksVendorLocation = FVector(6990.0, -1100.0, 1260.0); // Drinks Vendor
	const FVector generalGoodsStoreLocation = FVector(5340.0, 930.0, 1260.0); // General Goods Store
	const FVector restSpotLocation = FVector(4320.0, 1250.0, 1260.0); // Rest Spot (Future Tavern/Pub)
	const FVector meetSpotLocation = FVector(8770.0, 720.0, 1260.0); // Meet Spot for Conversation
	const FVector bedLocation = FVector(6790, 1810, 1260.0); // Home (Bed) House 12
};
