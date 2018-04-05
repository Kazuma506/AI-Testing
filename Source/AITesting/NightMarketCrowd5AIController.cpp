// Fill out your copyright notice in the Description page of Project Settings.

#include "NightMarketCrowd5AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ANightMarketCrowd5AIController::ANightMarketCrowd5AIController()
{
	atCrowd = false;
	atHome = true;

	destination1 = false;
	destination2 = true;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ANightMarketCrowd5AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ANightMarketCrowd5AIController::Tick(float DeltaTime)
{
	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(crowdLocation, 1.0f);

		atCrowd = true;

		destination1 = false;
	}

	if (destination2)
	{
		MoveToLocation(homeLocation, 1.0f);

		atHome = true;

		destination2 = false;
	}
}

void ANightMarketCrowd5AIController::MoveToCrowd()
{
	destination1 = true;

	hasRotated = true;
}

void ANightMarketCrowd5AIController::MoveHome()
{
	destination2 = true;
}

void ANightMarketCrowd5AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightMarketCrowd5AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;
	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightMarketCrowd5AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ANightMarketCrowd5AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -44, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 50, 0));
	}
}