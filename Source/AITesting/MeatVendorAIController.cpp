// Fill out your copyright notice in the Description page of Project Settings.

#include "MeatVendorAIController.h"
#include "AIMeatVendor.h"
#include "TimerManager.h"

AMeatVendorAIController::AMeatVendorAIController()
{
	atStand = false;
	atHome = true;

	destination1 = true;
	destination2 = false;

	hasRotated = true;

	timeAtStand = 800;
	timeAtHome = 400;

}

void AMeatVendorAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void AMeatVendorAIController::Tick(float DeltaTime)
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

void AMeatVendorAIController::MoveToStand()
{
	destination1 = true;

	hasRotated = true;
}

void AMeatVendorAIController::MoveHome()
{
	destination2 = true;
}

void AMeatVendorAIController::VillagerBehavior()
{
	if (atStand)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AMeatVendorAIController::MoveHome, timeAtStand, false);

		atStand = false;

	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AMeatVendorAIController::MoveToStand, timeAtHome, false);

		atHome = false;
	}
}

void AMeatVendorAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIMeatVendor* AIChar = Cast<AAIMeatVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 50, 0));

		hasRotated = false;
	}
	else
	{
		AAIMeatVendor* AIChar = Cast<AAIMeatVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -70, 0));
	}
}


