// Fill out your copyright notice in the Description page of Project Settings.

#include "ShopandRestAIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

AShopandRestAIController::AShopandRestAIController()
{
	atDrinksVendor = true;

	destination2 = true;

	waitTime1 = 80;
	waitTime2 = 30;
	waitTime3 = 60;
	waitTime4 = 250;
	waitTime5 = 380;
	waitTime6 = 400;
}


void AShopandRestAIController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);
}

void AShopandRestAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(vegeatableVendorLocation, 1.0f);

		atVegetableVendor = true;

		destination1 = false;
	}

	if (destination2)
	{
		MoveToLocation(drinksVendorLocation, 1.0f);

		atDrinksVendor = true;

		destination2 = false;
	}

	if (destination3)
	{
		MoveToLocation(generalGoodsStoreLocation, 1.0f);

		atGeneralGoodsStore = true;

		destination3 = false;
	}

	if (destination4)
	{
		MoveToLocation(restSpotLocation, 1.0f);

		atRestSpot = true;

		destination4 = false;
	}

	if (destination5)
	{
		MoveToLocation(meetSpotLocation, 1.0f);

		atMeetSpot = true;

		destination5 = false;
	}

	if (destination6)
	{
		MoveToLocation(bedLocation, 1.0f);

		atBed = true;

		destination6 = false;
	}
}

void AShopandRestAIController::MoveToVegetableVendor()
{
	destination1 = true;

	rotateAtVegetableVendor = true;
}

void AShopandRestAIController::MoveToDrinksVendor()
{
	destination2 = true;

	rotatAtDrinksVendor = true;
}

void AShopandRestAIController::MoveToGeneralGoodsStore()
{
	destination3 = true;

	rotateAtGeneralGoodsStore = true;
}

void AShopandRestAIController::MoveToRestSpot()
{
	destination4 = true;

	rotateAtRestSpot = true;
}

void AShopandRestAIController::MoveToMeetSpot()
{
	destination5 = true;

	rotateAtMeetSpot = true;
}

void AShopandRestAIController::MoveToBed()
{
	destination6 = true;

	rotateAtBed = true;
}

void AShopandRestAIController::VillagerBehavior()
{
	if (atVegetableVendor)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AShopandRestAIController::MoveToDrinksVendor, waitTime1, false);

		atVegetableVendor = false;

	}
	if (atDrinksVendor)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AShopandRestAIController::MoveToGeneralGoodsStore, waitTime2, false);

		atDrinksVendor = false;
	}

	if (atGeneralGoodsStore)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AShopandRestAIController::MoveToRestSpot, waitTime3, false);

		atGeneralGoodsStore = false;
	}

	if (atRestSpot)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AShopandRestAIController::MoveToMeetSpot, waitTime4, false);

		atRestSpot = false;
	}

	if (atMeetSpot)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AShopandRestAIController::MoveToBed, waitTime5, false);

		atMeetSpot = false;
	}

	if (atBed)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AShopandRestAIController::MoveToVegetableVendor, waitTime6, false);

		atBed = false;
	}
}

void AShopandRestAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (rotateAtVegetableVendor)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 90, 0));

		rotateAtVegetableVendor = false;
	}

	if (rotatAtDrinksVendor)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -136, 0));

		rotatAtDrinksVendor = false;
	}

	if (rotateAtGeneralGoodsStore)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -30, 0));

		rotateAtGeneralGoodsStore = false;
	}

	if (rotateAtRestSpot)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -90, 0));

		rotateAtRestSpot = false;
	}

	if (rotateAtMeetSpot)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -147, 0));

		rotateAtMeetSpot = false;
	}

	if (rotateAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -147, 0));

		rotateAtBed = false;
	}
}