// Fill out your copyright notice in the Description page of Project Settings.

#include "NightMarketCrowd6AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ANightMarketCrowd6AIController::ANightMarketCrowd6AIController()
{
	atCrowd = false;
	atHome = true;

	destination1 = false;
	destination2 = true;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ANightMarketCrowd6AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ANightMarketCrowd6AIController::Tick(float DeltaTime)
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

void ANightMarketCrowd6AIController::MoveToCrowd()
{
	destination1 = true;

	hasRotated = true;
}

void ANightMarketCrowd6AIController::MoveHome()
{
	destination2 = true;
}

void ANightMarketCrowd6AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightMarketCrowd6AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;
	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightMarketCrowd6AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ANightMarketCrowd6AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 154, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -70, 0));
	}
}


