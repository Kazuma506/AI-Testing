// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TravelerHeadingEastAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ATravelerHeadingEastAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATravelerHeadingEastAIController();

	virtual void Possess(APawn *InPawn) override;

	void Tick(float DeltaTime);

	void MoveEast();

	FTimerHandle PositionSwitchingHandle;

	const FVector WestLocation = FVector(6640, -1070.0, 1260.0); // End of Town heading east Location
	
	
	
};
