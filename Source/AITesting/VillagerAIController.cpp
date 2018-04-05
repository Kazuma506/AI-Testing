// Fill out your copyright notice in the Description page of Project Settings.

#include "VillagerAIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

AVillagerAIController::AVillagerAIController()
{
	waitTime1 = 300;
	waitTime2 = 60;
	waitTime3 = 60;
	waitTime4 = 380;
	waitTime5 = 400;

	atBlacksmithShop = false;
	atFruitVendor = true;
	atAlchemyShop = false;
	atMeetingPoint = false;
	atBed = false;

	destination1 = false;
	destination2 = true;
	destination3 = false;
	destination4 = false;
}


void AVillagerAIController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	acceptanceRadius = 1.0f;
}

void AVillagerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(blacksmithShopLocation, 1.0f);

		atBlacksmithShop = true;

		destination1 = false;
	}

	if (destination2)
	{
		MoveToLocation(fruitVendorLocation, 1.0f);

		atFruitVendor = true;

		destination2 = false;
	}

	if (destination3)
	{
		MoveToLocation(alchemyShopLocation, 1.0f);

		atAlchemyShop = true;

		destination3 = false;
	}

	if (destination4)
	{
		MoveToLocation(meetingPointLocation, 1.0f);

		atMeetingPoint = true;

		destination4 = false;
	}

	if (destination5)
	{
		MoveToLocation(bedLocation, 1.0f);

		atBed = true;

		destination4 = false;
	}
}


void AVillagerAIController::MoveToBlacksmithShop()
{
	destination1 = true;
	
	rotatedAtBlacksmithShop = true;
}

void AVillagerAIController::MoveToFruitVendor()
{
	destination2 = true;

	rotatedAtFruitVendor = true;
}

void AVillagerAIController::MoveToAlchemyShop()
{
	destination3 = true;
	
	rotatedAtAlchemyShop = true;
}

void AVillagerAIController::MoveToMeetingPoint()
{
	destination4 = true;
	
	rotatedAtMeetingPoint = true;
}

void AVillagerAIController::MoveToBed()
{
	destination5 = true;

	rotatedAtBed = true;
}

void AVillagerAIController::VillagerBehavior()
{
	if (atBlacksmithShop)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerAIController::MoveToFruitVendor, waitTime1, false);

		atBlacksmithShop = false;

	}
	if (atFruitVendor)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerAIController::MoveToAlchemyShop, waitTime2, false);

		atFruitVendor = false;
	}

	if (atAlchemyShop)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerAIController::MoveToMeetingPoint, waitTime3, false);

		atAlchemyShop = false;
	}

	if (atMeetingPoint)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerAIController::MoveToBed, waitTime4, false);

		atMeetingPoint = false;
	}
	
	if (atBed)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerAIController::MoveToBlacksmithShop, waitTime5, false);

		atBed = false;
	}

}

void AVillagerAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (rotatedAtBlacksmithShop)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 90, 0));

		rotatedAtBlacksmithShop = false;
	}

	if (rotatedAtFruitVendor)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -136, 0));

		rotatedAtFruitVendor = false;
	}

	if (rotatedAtAlchemyShop)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -30, 0));

		rotatedAtAlchemyShop = false;
	}

	if (rotatedAtMeetingPoint)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 90, 0));

		rotatedAtMeetingPoint = false;
	}

	if (rotatedAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -147, 0));

		rotatedAtBed = false;
	}
}