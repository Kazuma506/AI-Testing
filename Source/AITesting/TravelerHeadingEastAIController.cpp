// Fill out your copyright notice in the Description page of Project Settings.

#include "TravelerHeadingEastAIController.h"
#include "TimerManager.h"

ATravelerHeadingEastAIController::ATravelerHeadingEastAIController()
{

}

void ATravelerHeadingEastAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void ATravelerHeadingEastAIController::Tick(float DeltaTime)
{
	MoveEast();
}

void ATravelerHeadingEastAIController::MoveEast()
{
	MoveToLocation(WestLocation, 1.0f);
}



