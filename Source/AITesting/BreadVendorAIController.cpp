// Fill out your copyright notice in the Description page of Project Settings.

#include "BreadVendorAIController.h"
#include "AIBreadVendor.h"
#include "TimerManager.h"

ABreadVendorAIController::ABreadVendorAIController()
{
	atStand = false;
	atHome = true;

	destination1 = true;
	destination2 = false;

	hasRotated = true;

	timeAtStand = 400;
	timeAtHome = 800;
}

void ABreadVendorAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void ABreadVendorAIController::Tick(float DeltaTime)
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

void ABreadVendorAIController::MoveToStand()
{
	destination1 = true;

	hasRotated = true;
}

void ABreadVendorAIController::MoveHome()
{
	destination2 = true;
}

void ABreadVendorAIController::VillagerBehavior()
{
	if (atStand)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ABreadVendorAIController::MoveHome, timeAtStand, false);

		atStand = false;
	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ABreadVendorAIController::MoveToStand, timeAtHome, false);

		atHome = false;
	}
}

void ABreadVendorAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	if (hasRotated)
	{
		AAIBreadVendor* AIChar = Cast<AAIBreadVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 0, 0));

		hasRotated = false;
	}
	else
	{
		AAIBreadVendor* AIChar = Cast<AAIBreadVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 170, 0));
	}
}