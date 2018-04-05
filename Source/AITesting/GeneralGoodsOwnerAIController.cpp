// Fill out your copyright notice in the Description page of Project Settings.

#include "GeneralGoodsOwnerAIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

AGeneralGoodsOwnerAIController::AGeneralGoodsOwnerAIController()
{
	atCounter = false;
	atShelfUnit1 = true;
	atShelfUnit2 = false;
	atChair = false;
	atShelfUnit3 = false;
	atShelfUnit4 = false;
	atBed = false;

	rotatedAtCounter = false;
	rotatedAtShelfUnit1 = true;
	rotatedAtShelfUnit2 = false;
	rotatedAtChair = false;
	rotatedAtShelfUnit3 = false;
	rotatedAtShelfUnit4 = false;
	rotatedAtBed = false;

	destination1 = false;
	destination2 = true;
	destination3 = false;
	destination4 = false;
	destination5 = false;
	destination6 = false;
	destination7 = false;

	timeAtCounter = 660;
	timeAtShelfUnit1= 40;
	timeAtShelfUnit2 = 40;
	timeAtChair = 40;
	timeAtShelfUnit3 = 30;
	timeAtShelfUnit4 = 30;
	timeAtBed = 400;
}

void AGeneralGoodsOwnerAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void AGeneralGoodsOwnerAIController::Tick(float DeltaTime)
{
	//MoveToLocation(BlacksmithLocationTest, 5.0f);

	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(counterLocation, 1.0f);

		atCounter = true;

		destination1 = false;
	}

	if (destination2)
	{
		MoveToLocation(shelfUnit1Location, 1.0f);

		atShelfUnit1 = true;

		destination2 = false;
	}

	if (destination3)
	{
		MoveToLocation(shelfUnit2Location, 1.0f);

		atShelfUnit2 = true;

		destination3 = false;
	}

	if (destination4)
	{
		MoveToLocation(chairLocation, 1.0f);

		atChair = true;

		destination4 = false;
	}

	if (destination5)
	{
		MoveToLocation(shelfUnit3Location, 1.0f);

		atShelfUnit3 = true;

		destination5 = false;
	}

	if (destination6)
	{
		MoveToLocation(shelfUnit4Location, 1.0f);

		atShelfUnit4 = true;

		destination6 = false;
	}

	if (destination7)
	{
		MoveToLocation(bedLocation, 1.0f);

		atBed = true;

		destination7 = false;
	}
}

void AGeneralGoodsOwnerAIController::MoveToCounter()
{
	destination1 = true;

	rotatedAtCounter = true;
}

void AGeneralGoodsOwnerAIController::MoveToShelfUnit1()
{
	destination2 = true;

	rotatedAtShelfUnit1 = true;

}

void AGeneralGoodsOwnerAIController::MoveToShelfUnit2()
{
	destination3 = true;

	rotatedAtShelfUnit2 = true;
}

void AGeneralGoodsOwnerAIController::MoveToChair()
{
	destination4 = true;

	rotatedAtChair = true;
}

void AGeneralGoodsOwnerAIController::MoveToShelfUnit3()
{
	destination5 = true;

	rotatedAtShelfUnit3 = true;
}

void AGeneralGoodsOwnerAIController::MoveToShelfUnit4()
{
	destination6 = true;

	rotatedAtShelfUnit4 = true;
}

void AGeneralGoodsOwnerAIController::MoveToBed()
{
	destination7 = true;

	rotatedAtBed = true;
}

void AGeneralGoodsOwnerAIController::VillagerBehavior()
{
	if (atShelfUnit1)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AGeneralGoodsOwnerAIController::MoveToShelfUnit2, timeAtShelfUnit1, false);

		atShelfUnit1 = false;
	}

	if (atShelfUnit2)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AGeneralGoodsOwnerAIController::MoveToChair, timeAtShelfUnit2, false);

		atShelfUnit2 = false;
	}

	if (atChair)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AGeneralGoodsOwnerAIController::MoveToShelfUnit3, timeAtChair, false);

		atChair = false;
	}

	if (atShelfUnit3)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AGeneralGoodsOwnerAIController::MoveToShelfUnit4, timeAtShelfUnit3, false);

		atShelfUnit3 = false;
	}

	if (atShelfUnit4)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AGeneralGoodsOwnerAIController::MoveToCounter, timeAtShelfUnit4, false);

		atShelfUnit4;
	}
	if (atCounter)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AGeneralGoodsOwnerAIController::MoveToBed, timeAtCounter, false);

		atCounter = false;
	}

	if (atBed)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AGeneralGoodsOwnerAIController::MoveToShelfUnit1, timeAtBed, false);

		atBed = false;
	}
}

void AGeneralGoodsOwnerAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (rotatedAtCounter)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -100, 0));

		rotatedAtCounter = false;
	}
	
	if(rotatedAtShelfUnit1)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 160, 0));

		rotatedAtShelfUnit1 = false;
	}

	if (rotatedAtShelfUnit2)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -100, 0));

		rotatedAtShelfUnit2 = false;
	}

	if (rotatedAtChair)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -100, 0));

		rotatedAtChair = false;
	}

	if (rotatedAtShelfUnit3)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -93, 0));

		rotatedAtShelfUnit3 = false;
	}

	if (rotatedAtShelfUnit4)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 0, 0));

		rotatedAtShelfUnit4 = false;
	}

	if (rotatedAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 30, 0));

		rotatedAtBed = false;
	}

}

