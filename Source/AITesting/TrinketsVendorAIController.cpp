// Fill out your copyright notice in the Description page of Project Settings.

#include "TrinketsVendorAIController.h"
#include "AITrinketsVendor.h"
#include "TimerManager.h"

ATrinketsVendorAIController::ATrinketsVendorAIController()
{
	AtStand = false;
	AtHome = true;

	destination1 = true;
	destination2 = false;

	HasRotated = true;

	TimeAtStand = 800;
	TimeAtHome = 400;

}

void ATrinketsVendorAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

}

void ATrinketsVendorAIController::Tick(float DeltaTime)
{
	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(StandLocation, 1.0f);

		AtStand = true;

		destination1 = false;
	}

	if (destination2)
	{
		MoveToLocation(HomeLocation, 1.0f);

		AtHome = true;

		destination2 = false;
	}
}

void ATrinketsVendorAIController::MoveToStand()
{
	destination1 = true;

	HasRotated = true;
}

void ATrinketsVendorAIController::MoveHome()
{
	destination2 = true;
}

void ATrinketsVendorAIController::VillagerBehavior()
{
	if (AtStand)
	{
		GetWorldTimerManager().SetTimer(PositionSwitchingHandle, this, &ATrinketsVendorAIController::MoveHome, TimeAtStand, false);

		AtStand = false;

	}
	if (AtHome)
	{
		GetWorldTimerManager().SetTimer(PositionSwitchingHandle, this, &ATrinketsVendorAIController::MoveToStand, TimeAtHome, false);

		AtHome = false;
	}
}
void ATrinketsVendorAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (HasRotated)
	{
		AAITrinketsVendor* AIChar = Cast<AAITrinketsVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 180, 0));

		HasRotated = false;
	}
	else
	{
		AAITrinketsVendor* AIChar = Cast<AAITrinketsVendor>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -30, 0));
	}
}


