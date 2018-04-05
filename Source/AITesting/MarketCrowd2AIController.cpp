// Fill out your copyright notice in the Description page of Project Settings.

#include "MarketCrowd2AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

AMarketCrowd2AIController::AMarketCrowd2AIController()
{
	atCrowd = true;
	atHome = false;

	hasRotated = true;

	destination1 = true;
	destination2 = false;

	timeAtCrowd = 60;
	timeAtHome = 60;
}

void AMarketCrowd2AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void AMarketCrowd2AIController::Tick(float DeltaTime)
{
	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(standLocation, 1.0f);

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

void AMarketCrowd2AIController::MoveToCrowd()
{
	destination1 = true;
	
	hasRotated = true;
}

void AMarketCrowd2AIController::MoveHome()
{
	destination2 = true;
}

void AMarketCrowd2AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AMarketCrowd2AIController::MoveHome, timeAtHome, false);

		atCrowd = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AMarketCrowd2AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void AMarketCrowd2AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 180, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -30, 0));
	}
}

