// Fill out your copyright notice in the Description page of Project Settings.

#include "TravelerHeadingWestAIController.h"
#include "TimerManager.h"

ATravelerHeadingWestAIController::ATravelerHeadingWestAIController()
{

}

void ATravelerHeadingWestAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void ATravelerHeadingWestAIController::Tick(float DeltaTime)
{
	MoveWest();
}

void ATravelerHeadingWestAIController::MoveWest()
{
	MoveToLocation(WestLocation, 1.0f);
}

