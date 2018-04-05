// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIBlacksmith.h"
#include "AIController.h"
#include "VillagerAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AVillagerAIController : public AAIController
{
	GENERATED_BODY()
public:
	AVillagerAIController();

	virtual void Possess(class APawn* InPawn) override;
	virtual void Tick(float DeltaSeconds) override;
	void MoveToBlacksmithShop();
	void MoveToFruitVendor();
	void MoveToAlchemyShop();
	void MoveToMeetingPoint();
	void MoveToBed();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atBlacksmithShop;
	bool atFruitVendor;
	bool atAlchemyShop;
	bool atMeetingPoint;
	bool atBed;

	bool rotatedAtBlacksmithShop;
	bool rotatedAtFruitVendor;
	bool rotatedAtAlchemyShop;
	bool rotatedAtMeetingPoint;
	bool rotatedAtBed;

	bool destination1;
	bool destination2;
	bool destination3;
	bool destination4;
	bool destination5;

	float acceptanceRadius;

	float waitTime1;
	float waitTime2;
	float waitTime3;
	float waitTime4;
	float waitTime5;

	FTimerHandle waitTimerHandle;

	const FVector blacksmithShopLocation = FVector(4980, -1130.0, 1260.0);
	const FVector fruitVendorLocation = FVector(6350.0, -1090.0, 1260.0);
	const FVector alchemyShopLocation = FVector(7040.0, 880.0, 1260.0);
	const FVector meetingPointLocation = FVector(8770.0, 590.0, 1260.0);
	const FVector bedLocation = FVector(5130.0, -1530.0, 1260.0);
};
