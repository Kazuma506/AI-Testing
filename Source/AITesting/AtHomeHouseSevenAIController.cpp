// Fill out your copyright notice in the Description page of Project Settings.

#include "AtHomeHouseSevenAIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

AAtHomeHouseSevenAIController::AAtHomeHouseSevenAIController()
{
	atFire = false;
	atPantry = true;
	atChair = false;
	outstide = false;
	atBed = false;

	rotatedAtPantry = true;

	destination1 = false;
	destination2 = true;
	destination3 = false;
	destination4 = false;
	destination5 = false;

	timeAtFire = 200;
	timeAtPantry = 50;
	timeAtChair = 500;
	timeOutside = 50;
	timeAtBed = 400;
}

void AAtHomeHouseSevenAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void AAtHomeHouseSevenAIController::Tick(float DeltaTime)
{
	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(fireLocation, 1.0f);

		atFire = true;

		destination1 = false;
	}

	if (destination2 == true)
	{
		MoveToLocation(pantryLocation, 1.0f);

		atPantry = true;

		destination2 = false;
	}

	if (destination3)
	{
		MoveToLocation(chairLocation, 1.0f);

		atChair = true;

		destination3 = false;
	}

	if (destination4)
	{
		MoveToLocation(outsideLocation, 1.0f);

		outstide = true;

		destination4 = false;
	}

	if (destination5)
	{
		MoveToLocation(bedLocation, 1.0f);

		atBed = true;

		destination5 = false;
	}
}

void AAtHomeHouseSevenAIController::MoveToFire()
{
	destination1 = true;

	rotatedAtFire = true;
}

void AAtHomeHouseSevenAIController::MoveToPantry()
{
	destination2 = true;

	rotatedAtPantry = true;
}

void AAtHomeHouseSevenAIController::MoveToChair()
{
	destination3 = true;

	rotatedAtChair = true;
}

void AAtHomeHouseSevenAIController::MoveOutside()
{
	destination4 = true;

	rotatedOutside = true;
}

void AAtHomeHouseSevenAIController::MoveToBed()
{
	destination5 = true;

	rotatedAtBed = true;
}

void AAtHomeHouseSevenAIController::VillagerBehavior()
{
	if (atFire)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAtHomeHouseSevenAIController::MoveToPantry, timeAtFire, false);

		atFire = false;
	}
	if (atPantry)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAtHomeHouseSevenAIController::MoveToChair, timeAtPantry, false);

		atPantry = false;
	}

	if (atChair)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAtHomeHouseSevenAIController::MoveOutside, timeAtChair, false);

		atChair = false;
	}

	if (outstide)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAtHomeHouseSevenAIController::MoveToBed, timeOutside, false);

		outstide = false;
	}

	if (atBed)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAtHomeHouseSevenAIController::MoveToFire, timeAtBed, false);

		atBed = false;
	}

}

void AAtHomeHouseSevenAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (rotatedAtFire)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 90, 0));

		rotatedAtFire = false;
	}

	if (rotatedAtPantry)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 180, 0));

		rotatedAtPantry = false;
	}

	if (rotatedAtChair)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 150, 0));

		rotatedAtChair = false;
	}

	if (rotatedOutside)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -90, 0));

		rotatedOutside = false;
	}

	if (rotatedAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 0, 0));

		rotatedAtBed = false;
	}
}


