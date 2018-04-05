// Fill out your copyright notice in the Description page of Project Settings.

#include "FruitVendorAIController.h"
#include "AIFruitVendor.h"
#include "TimerManager.h"

AFruitVendorAIController::AFruitVendorAIController()
{
	atStand = false;
	atHome = true;

	destination1 = true;
	destination2 = false;

	hasRotated = true;

	timeAtStand = 800;
	timeAtHome = 400;
}

void AFruitVendorAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void AFruitVendorAIController::Tick(float DeltaTime)
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

void AFruitVendorAIController::MoveToStand()
{
	destination1 = true;

	hasRotated = true;
}

void AFruitVendorAIController::MoveHome()
{
	destination2 = true;
}

void AFruitVendorAIController::VillagerBehavior()
{
	if (atStand)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AFruitVendorAIController::MoveHome, timeAtStand, false);

		atStand = false;
	}
	if (atHome)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AFruitVendorAIController::MoveToStand, timeAtHome, false);

		atHome = false;
	}
}

void AFruitVendorAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (hasRotated)
	{
		AAIFruitVendor* AIChar = Cast<AAIFruitVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 20, 0));

		hasRotated = true;
	}
	else
	{
		AAIFruitVendor* AIChar = Cast<AAIFruitVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 170, 0));
	}
}

