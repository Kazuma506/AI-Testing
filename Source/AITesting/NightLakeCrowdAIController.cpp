// Fill out your copyright notice in the Description page of Project Settings.

#include "NightLakeCrowdAIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

ANightLakeCrowdAIController::ANightLakeCrowdAIController()
{
	atCrowd = true;
	atHome = false;

	destination1 = true;
	destination2 = false;

	timeAtCrowd = 800;
	timeAtHome = 400;
}

void ANightLakeCrowdAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ANightLakeCrowdAIController::Tick(float DeltaTime)
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

void ANightLakeCrowdAIController::MoveToCrowd()
{
	destination1 = true;
}

void ANightLakeCrowdAIController::MoveHome()
{
	destination2 = true;
}

void ANightLakeCrowdAIController::VillagerBehavior()
{
	if (atCrowd)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightLakeCrowdAIController::MoveHome, timeAtCrowd, false);

		atCrowd = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ANightLakeCrowdAIController::MoveToCrowd, timeAtHome, false);

		atHome = false;
	}
}

void ANightLakeCrowdAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (rotateAtLake)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 2, 0));

		rotateAtLake = false;
	}

	if (rotateAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 164, 0));

		rotateAtBed = false;
	}
}


