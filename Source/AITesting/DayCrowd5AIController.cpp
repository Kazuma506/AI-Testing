// Fill out your copyright notice in the Description page of Project Settings.

#include "DayCrowd5AIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ADayCrowd5AIController::ADayCrowd5AIController()
{
	atCrowd = true;
	atHome = false;

	hasRotated = true;

	destination1 = true;
	destination2 = false;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ADayCrowd5AIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void ADayCrowd5AIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
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

void ADayCrowd5AIController::MoveToCrowd()
{
	destination1 = true;

	hasRotated = true;
}

void ADayCrowd5AIController::MoveHome()
{
	destination2 = true;
}

void ADayCrowd5AIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayCrowd5AIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;
	}

	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ADayCrowd5AIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ADayCrowd5AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -143, 0));

		hasRotated = false;
	}
	else
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -70, 0));
	}
}



