// Fill out your copyright notice in the Description page of Project Settings.

#include "NightLakeCrowd2AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ANightLakeCrowd2AIController::ANightLakeCrowd2AIController()
{
	atCrowd = true;
	atHome = false;

	destination1 = true;
	destination2 = false;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ANightLakeCrowd2AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void ANightLakeCrowd2AIController::Tick(float DeltaTime)
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

void ANightLakeCrowd2AIController::MoveToCrowd()
{
	destination1 = true;
}

void ANightLakeCrowd2AIController::MoveHome()
{
	destination2 = true;
}

void ANightLakeCrowd2AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightLakeCrowd2AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightLakeCrowd2AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ANightLakeCrowd2AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (rotateAtLake)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -170, 0));

		rotateAtLake = false;
	}

	if (rotateAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -137, 0));

		rotateAtBed = false;
	}
}

