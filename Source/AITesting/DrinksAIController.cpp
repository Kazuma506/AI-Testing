// Fill out your copyright notice in the Description page of Project Settings.

#include "DrinksAIController.h"
#include "AIDrinksVendor.h"
#include "TimerManager.h"

ADrinksAIController::ADrinksAIController()
{
	atStand = false;
	atHome = true;

	destination1 = true;
	destination2 = false;

	hasRotated = true;

	timeAtStand = 800;
	timeAtHome = 400;

}

void ADrinksAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ADrinksAIController::Tick(float DeltaTime)
{
	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(standLocation, 1.0f);

		atStand = true;

		destination1 = false;
	}

	if (destination2)
	{
		MoveToLocation(homeLocation, 1.0f);

		atHome = true;

		destination2 = false;
	}
}

void ADrinksAIController::MoveToStand()
{
	destination1 = true;

	hasRotated = true;
}

void ADrinksAIController::MoveHome()
{
	destination2 = true;
}

void ADrinksAIController::VillagerBehavior()
{
	if (atStand)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADrinksAIController::MoveHome, timeAtStand, false);

		atStand = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADrinksAIController::MoveToStand, timeAtHome, false);

		atHome = false;
	}
}

void ADrinksAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIDrinksVendor* AIChar = Cast<AAIDrinksVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 140, 0));

		hasRotated = false;
	}
	else
	{
		AAIDrinksVendor* AIChar = Cast<AAIDrinksVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -70, 0));
	}
}

