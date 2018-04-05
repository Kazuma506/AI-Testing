// Fill out your copyright notice in the Description page of Project Settings.

#include "MarketCrowdAIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

AMarketCrowdAIController::AMarketCrowdAIController()
{
	atCrowd = true;
	atHome = false;

	destination1 = true;
	destination2 = false;

	hasRotated = true;

	timeAtCrowd = 60;
	timeAtHome = 60;
}

void AMarketCrowdAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void AMarketCrowdAIController::Tick(float DeltaTime)
{
	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(standLocation, 1.0f);

		atCrowd = true;

		destination1 = false;
	}

	if (destination2 == true)
	{
		MoveToLocation(homeLocation, 1.0f);

		atHome = true;

		destination2 = false;
	}
}

void AMarketCrowdAIController::MoveToCrowd()
{
	destination1 = true;
}

void AMarketCrowdAIController::MoveHome()
{
	destination2 = true;
}

void AMarketCrowdAIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AMarketCrowdAIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AMarketCrowdAIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void AMarketCrowdAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 0, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -30, 0));
	}
}



