// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TravelerHeadingWestAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ATravelerHeadingWestAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATravelerHeadingWestAIController();

	virtual void Possess(APawn *InPawn) override;

	void Tick(float DeltaTime);

	void MoveWest();

	FTimerHandle PositionSwitchingHandle;

	const FVector WestLocation = FVector(-3350, -1650.0, 1260.0); // End of Town heading west Location
};
