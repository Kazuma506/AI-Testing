// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TestingAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API ATestingAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATestingAIController();
	void Tick(float DeltaTime);
	
	FString Blacksmith = TEXT("Blacksmith Shop");
	TArray<FVector> locations = { FVector(5090, -700, 1260) };
	
};
