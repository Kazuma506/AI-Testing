// Fill out your copyright notice in the Description page of Project Settings.

#include "DayTimeCrowd1AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ADayTimeCrowd1AIController::ADayTimeCrowd1AIController()
{
	atCrowd = false;
	atHome = true;

	hasRotated = true;

	destination1 = true;
	destination2 = false;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ADayTimeCrowd1AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ADayTimeCrowd1AIController::Tick(float DeltaTime)
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

void ADayTimeCrowd1AIController::MoveToCrowd()
{
	destination1 = true;

	hasRotated = true;
}

void ADayTimeCrowd1AIController::MoveHome()
{
	destination2 = true;
}

void ADayTimeCrowd1AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayTimeCrowd1AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayTimeCrowd1AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ADayTimeCrowd1AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -150, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 20, 0));
	}
}

