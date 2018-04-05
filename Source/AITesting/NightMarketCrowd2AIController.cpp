// Fill out your copyright notice in the Description page of Project Settings.

#include "NightMarketCrowd2AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ANightMarketCrowd2AIController::ANightMarketCrowd2AIController()
{
	atCrowd = false;
	atHome = true;

	destination1 = false;
	destination2 = true;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ANightMarketCrowd2AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void ANightMarketCrowd2AIController::Tick(float DeltaTime)
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

void ANightMarketCrowd2AIController::MoveToCrowd()
{
	destination1 = true;

	hasRotated = true;
}

void ANightMarketCrowd2AIController::MoveHome()
{
	destination2 = true;
}

void ANightMarketCrowd2AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightMarketCrowd2AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightMarketCrowd2AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ANightMarketCrowd2AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 147, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -160, 0));
	}
}