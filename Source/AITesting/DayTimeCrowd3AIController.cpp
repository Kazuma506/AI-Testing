// Fill out your copyright notice in the Description page of Project Settings.

#include "DayTimeCrowd3AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ADayTimeCrowd3AIController::ADayTimeCrowd3AIController()
{
	atCrowd = true;
	atHome = false;

	hasRotated = true;

	destination1 = true;
	destination2 = false;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ADayTimeCrowd3AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ADayTimeCrowd3AIController::Tick(float DeltaTime)
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

void ADayTimeCrowd3AIController::MoveToCrowd()
{
	destination1 = true;

	hasRotated = true;
}

void ADayTimeCrowd3AIController::MoveHome()
{
	destination2 = true;
}

void ADayTimeCrowd3AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayTimeCrowd3AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;
	}

	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayTimeCrowd3AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ADayTimeCrowd3AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -60, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -70, 0));
	}
}

