// Fill out your copyright notice in the Description page of Project Settings.

#include "DayCrowd4AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ADayCrowd4AIController::ADayCrowd4AIController()
{
	atCrowd = true;
	atHome = false;

	hasRotated = true;

	destination1 = true;
	destination2 = false;

	timeAtCrowd = 800;
	timeAtHome = 400;

}

void ADayCrowd4AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ADayCrowd4AIController::Tick(float DeltaTime)
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

void ADayCrowd4AIController::MoveToCrowd()
{
	destination1 = true;

	hasRotated = true;
}

void ADayCrowd4AIController::MoveHome()
{
	destination2 = true;
}

void ADayCrowd4AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayCrowd4AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;
	}

	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayCrowd4AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ADayCrowd4AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 140, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -70, 0));
	}
}







