// Fill out your copyright notice in the Description page of Project Settings.

#include "VegatableAIController.h"
#include "AIVegetableVendor.h"
#include "TimerManager.h"

AVegatableAIController::AVegatableAIController()
{
	atStand = false;
	atHome = true;

	destination1 = true;
	destination2 = false;

	hasRotated = true;

	timeAtStand = 800;
	timeAtHome = 400;

}

void AVegatableAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void AVegatableAIController::Tick(float DeltaTime)
{
	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(standLocation, 1.0f);

		atStand = true;

		destination1 = false;
	}

	if (destination2)
	{
		MoveToLocation(homeLocation, 1.0f);

		atHome = true;

		destination2 = false;
	}
}

void AVegatableAIController::MoveToStand()
{
	destination1 = true;

	hasRotated = true;
}

void AVegatableAIController::MoveHome()
{
	destination2 = true;
}

void AVegatableAIController::VillagerBehavior()
{
	if (atStand)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AVegatableAIController::MoveHome, timeAtStand, false);

		atStand = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AVegatableAIController::MoveToStand, timeAtHome, false);

		atHome = false;
	}
}

void AVegatableAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIVegetableVendor* AIChar = Cast<AAIVegetableVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 110, 0));

		hasRotated = false;
	}
	else
	{
		AAIVegetableVendor* AIChar = Cast<AAIVegetableVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -70, 0));
	}
}


