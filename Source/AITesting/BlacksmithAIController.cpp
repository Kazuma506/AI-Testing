// Fill out your copyright notice in the Description page of Project Settings.


#include "BlacksmithAIController.h"
#include "TimerManager.h"
#include "AIBlacksmith.h"

ABlacksmithAIController::ABlacksmithAIController()
{
	atForge = false;
	atAnvil = true;
	atChair = false;
	atBed = false;
	atBreakSpot = false;

	 destination1 = false;
	 destination2 = true;
	 destination3 = false;
	 destination4 = false;
	 destination5 = false;

	timeAtAnvil = 300;
	timeAtForge = 300;
	timeAtChair = 50;
	timeAtBreakSpot = 150;
	timeAtBed = 400;
}

void ABlacksmithAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void ABlacksmithAIController::Tick(float DeltaTime)
{
	BlacksmithBehavior();

	if (destination1)
	{
		AAIBlacksmith *Blacksmith = Cast<AAIBlacksmith>(GetPawn());

		MoveToLocation(anvilLocation, 1.0f);

		Blacksmith->SetActorRelativeRotation(FRotator(0, 80, 0));

		atAnvil = true;

		destination1 = false;
	}
	
	if (destination2)
	{
		AAIBlacksmith *Blacksmith = Cast<AAIBlacksmith>(GetPawn());

		MoveToLocation(forgeLocation, 1.0f);
		Blacksmith->SetActorRelativeRotation(FRotator(0, 0, 0));

		atForge = true;

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
		MoveToLocation(bedLocation, 1.0f);

		atBed = true;

		destination4 = false;
	}

	if (destination5)
	{
		MoveToLocation(breakSpotLocation, 1.0f);

		atBreakSpot = true;

		destination5 = false;
	}

}

void ABlacksmithAIController::MoveToForge()
{
	destination2 = true;
}

void ABlacksmithAIController::MoveToAnvil()
{
	destination1 = true;

	rotatedAtAnvil = true;
}

void ABlacksmithAIController::MoveToChair()
{
	destination3 = true;
}

void ABlacksmithAIController::MoveToBed()
{
	destination4 = true;
}

void ABlacksmithAIController::MoveToBreakSpot()
{
	destination5 = true;

	rotatedAtBreakSpot = true;
}

void ABlacksmithAIController::BlacksmithBehavior()
{
	if (atAnvil)
	{

		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ABlacksmithAIController::MoveToForge, timeAtAnvil, false);

		atAnvil = false;

	}
	if (atForge)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ABlacksmithAIController::MoveToChair, timeAtAnvil, false);

		atForge = false;
	}

	if (atChair)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ABlacksmithAIController::MoveToBed, timeAtAnvil, false);

		atChair = false;
	}

	if (atBed)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ABlacksmithAIController::MoveToBreakSpot, timeAtAnvil, false);

		atBed = false;
	}

	if (atBreakSpot)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &ABlacksmithAIController::MoveToAnvil, timeAtAnvil, false);

		atBreakSpot = false;
	}
}

void ABlacksmithAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (rotatedAtAnvil)
	{
		AAIBlacksmith* AIChar = Cast<AAIBlacksmith>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 84, 0));

		rotatedAtAnvil = false;
	}
	if(rotatedAtBreakSpot)
	{
		AAIBlacksmith* AIChar = Cast<AAIBlacksmith>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -120, 0));

		rotatedAtBreakSpot = false;
	}
}