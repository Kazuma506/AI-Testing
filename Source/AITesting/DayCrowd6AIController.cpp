// Fill out your copyright notice in the Description page of Project Settings.

#include "DayCrowd6AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ADayCrowd6AIController::ADayCrowd6AIController()
{
	atCrowd = true;
	atHome = false;

	destination1 = true;
	destination2 = false;

	hasRotated = true;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ADayCrowd6AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ADayCrowd6AIController::Tick(float DeltaTime)
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

void ADayCrowd6AIController::MoveToCrowd()
{
	atCrowd = true;

	destination1 = true;
}

void ADayCrowd6AIController::MoveHome()
{
	atHome = true;

	destination2 = true;
}

void ADayCrowd6AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayCrowd6AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;

	}

	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayCrowd6AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ADayCrowd6AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 41, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 110, 0));
	}
}



