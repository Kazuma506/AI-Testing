// Fill out your copyright notice in the Description page of Project Settings.

#include "AlchemyStoreOwnerAIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

AAlchemyStoreOwnerAIController::AAlchemyStoreOwnerAIController()
{
	atTable = false;
	atAlchemyPot = true;
	atChair = false;
	atPotionShelf = false;
	atBed = false;

	rotatedAtTable = false;
	rotatedAtAlchemyPot = true;
	rotatedAtChair = false;
	rotatedAtPotionShelf = false;
	rotatedAtBed = false;

	destination1 = false;
	destination2 = true;
	destination3 = false;
	destination4 = false;
	destination5 = false;
	destination6 = false;
	destination7 = false;

	timeAtTable = 660;
	timeAtAlchemyPot = 40;
	timeAtChair = 40;
	timeAtPotionShelf = 60;
	timeAtBed = 400;
}

void AAlchemyStoreOwnerAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void AAlchemyStoreOwnerAIController::Tick(float DeltaTime)
{
	VillagerBehavior();

	if (destination1)
	{
		// Moves AI to the the table
		MoveToLocation(tableLocation, 1.0f);

		atTable = true;

		destination1 = false;
	}

	if (destination2)
	{
		// Moves AI to the alchemy pot
		MoveToLocation(alchemyPotLocation, 1.0f);

		atAlchemyPot = true;

		destination2 = false;
	}

	if (destination3)
	{
		// Moves AI to the chair
		MoveToLocation(chairLocation, 1.0f);

		atChair = true;

		destination3 = false;
	}

	if (destination4)
	{
		// Moves AI to the potion shelf
		MoveToLocation(potionShelfLocation, 1.0f);

		atPotionShelf = true;

		destination4 = false;
	}

	if (destination5)
	{
		// Moves AI to the bed
		MoveToLocation(bedLocation, 1.0f);

		atBed = true;

		destination5 = false;
	}
}

void AAlchemyStoreOwnerAIController::MoveToTable()
{
	// enables AI movement
	destination1 = true;

	// enables AI rotation once move is completed
	rotatedAtTable = true;
}

void AAlchemyStoreOwnerAIController::MoveToAlchemyPot()
{
	// enables AI movement
	destination2 = true;

	// enables AI rotation once move is completed
	rotatedAtAlchemyPot = true;
}

void AAlchemyStoreOwnerAIController::MoveToChair()
{
	// enables AI movement
	destination3 = true;

	// enables AI rotation once move is completed
	rotatedAtChair = true;
}

void AAlchemyStoreOwnerAIController::MoveToPotionShelf()
{
	// enables AI movement
	destination4 = true;

	// enables AI rotation once move is completed
	rotatedAtPotionShelf = true;
}

void AAlchemyStoreOwnerAIController::MoveToBed()
{
	// enables AI movement
	destination5 = true;

	// enables AI rotation once move is completed
	rotatedAtBed = true;
}

// Calls function to move the AI after the timer ends
void AAlchemyStoreOwnerAIController::VillagerBehavior()
{
	if (atTable)
	{
		// After the timer ends call function MoveToAlchemyPot
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAlchemyStoreOwnerAIController::MoveToAlchemyPot, timeAtTable, false);

		atTable = false;
	}

	if (atAlchemyPot)
	{
		// After the timer ends call function MoveToChair
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAlchemyStoreOwnerAIController::MoveToChair, timeAtAlchemyPot, false);

		atAlchemyPot = false;
	}

	if (atChair)
	{
		// After the timer ends call function MoveToPotionShelf
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAlchemyStoreOwnerAIController::MoveToPotionShelf, timeAtChair, false);

		atChair = false;
	}

	if (atPotionShelf)
	{
		// After the timer ends call function MoveToBed
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAlchemyStoreOwnerAIController::MoveToBed, timeAtPotionShelf, false);

		atPotionShelf = false;
	}

	if (atBed)
	{
		// After the timer ends call function MoveToTable
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AAlchemyStoreOwnerAIController::MoveToTable, timeAtBed, false);

		atBed = false;
	}
}

// Sets the AI Rotation to make the AI face the correct way when they arrive at their destination
void AAlchemyStoreOwnerAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (rotatedAtTable)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -95, 0));

		rotatedAtBed = false;
	}

	if (rotatedAtAlchemyPot)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 85, 0));

		rotatedAtAlchemyPot = false;
	}

	if (rotatedAtChair)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 164, 0));

		rotatedAtChair = false;
	}

	if (rotatedAtPotionShelf)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 85, 0));

		rotatedAtPotionShelf = false;
	}

	if (rotatedAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -170, 0));

		rotatedAtBed = false;
	}
}