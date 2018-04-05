// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NewAISystemExperiment.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ANewAISystemExperiment : public AAIController
{
	GENERATED_BODY()

public:
	ANewAISystemExperiment();

	UFUNCTION()
	void MoveToDestination(FString Destination);
	
	TArray<FString> locationNames = {"BlacksmithShop", "HouseTen"};
	TArray<FVector> locations = {FVector(5090, -700, 1260)};
	int arrayPosition;
	bool locationFound;
	const FVector FinalDestination = FVector(5090, -700, 1260);
};
