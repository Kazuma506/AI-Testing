// Fill out your copyright notice in the Description page of Project Settings.


#include "VillagerVendorRouteAIController.h"
#include"AIVillager.h"
#include "TimerManager.h"

AVillagerVendorRouteAIController::AVillagerVendorRouteAIController()
{

	waitTime1 = 60;
	waitTime2 = 20;
	waitTime3 = 20;
	waitTime4 = 20;
	waitTime5 = 20;
	waitTime6 = 30;
	waitTime7 = 60;
	waitTime8 = 60;

	destination1 = false;
	destination2 = true;
	destination3 = false;
	destination4 = false;
	destination5 = false;
	destination6 = false;
	destination7 = false;
	destination8 = false;
}


void AVillagerVendorRouteAIController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);
	acceptanceRadius = 1.0f;

}

void AVillagerVendorRouteAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	VillagerBehavior();

	if (destination1)
	{
		MoveToLocation(breadVendorLocation, acceptanceRadius);

		atBreadVendor = true;

		destination1 = false;
	}

	if (destination2)
	{
		MoveToLocation(fruitVendorLocation, acceptanceRadius);

		atFruitVendor = true;

		destination2 = false;
	}

	if (destination3)
	{
		MoveToLocation(meatVendorLocation, acceptanceRadius);

		atMeatVendor = true;

		destination3 = false;
	}

	if (destination4)
	{
		MoveToLocation(vegetableVendorLocation, acceptanceRadius);

		atVegetableVendor = true;

		destination4 = false;
	}

	if (destination5)
	{
		MoveToLocation(drinksVendorLocation, acceptanceRadius);

		atDrinksVendor = true;

		destination5 = false;
	}

	if (destination6)
	{
		MoveToLocation(pantryLocation, acceptanceRadius);

		atPantry = true;

		destination6 = false;
	}

	if (destination7)
	{
		MoveToLocation(houseTenLocation, acceptanceRadius);

		atHouseTen = true;

		destination7 = false;
	}

	if (destination8)
	{
		MoveToLocation(bedLocation, acceptanceRadius);

		atBed = true;

		destination8 = false;
	}
}


void AVillagerVendorRouteAIController::MoveToBreadVendor()
{
	destination1 = true;
	
	rotatedAtBreadVendor = true;
}

void AVillagerVendorRouteAIController::MoveToFruitVendor()
{
	destination2 = true;

	rotatedAtFruitVendor = true;
}

void AVillagerVendorRouteAIController::MoveToMeatVendor()
{
	destination3 = true;

	rotatedAtMeatVendor = true;
}

void AVillagerVendorRouteAIController::MoveToVegetableVendor()
{
	destination4 = true;

	rotatedAtVegetableVendor = true;
}

void AVillagerVendorRouteAIController::MoveToDrinksVendor()
{
	destination5 = true;

	rotatedAtDrinksVendor = true;
}


void AVillagerVendorRouteAIController::MoveToPantry()
{
	destination6 = true;

	rotatedAtPantry = true;
}

void AVillagerVendorRouteAIController::MoveToHouseTen()
{
	destination7 = true;

	rotatedAtHouseTen = true;
}

void AVillagerVendorRouteAIController::MoveToBed()
{
	destination8 = true;

	rotatedAtBed = true;
}


void AVillagerVendorRouteAIController::VillagerBehavior()
{
	if (atBreadVendor)
	{

		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerVendorRouteAIController::MoveToFruitVendor, waitTime1, false);

		atBreadVendor = false;
	}
	if (atFruitVendor)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerVendorRouteAIController::MoveToMeatVendor, waitTime2, false);

		atFruitVendor = false;
	}

	if (atMeatVendor)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerVendorRouteAIController::MoveToVegetableVendor, waitTime3, false);

		atMeatVendor = false;
	}

	if (atVegetableVendor)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerVendorRouteAIController::MoveToDrinksVendor, waitTime4, false);

		atVegetableVendor = false;
	}

	if (atDrinksVendor)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerVendorRouteAIController::MoveToPantry, waitTime5, false);

		atDrinksVendor = false;
	}


	if (atPantry)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerVendorRouteAIController::MoveToHouseTen, waitTime6, false);

		atPantry = false;
	}

	if (atHouseTen)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerVendorRouteAIController::MoveToBed, waitTime7, false);

		atHouseTen = false;
	}

	if (atBed)
	{
		GetWorldTimerManager().SetTimer(waitTimerHandle, this, &AVillagerVendorRouteAIController::MoveToBreadVendor, waitTime8, false);

		atBed = false;
	}

}

void AVillagerVendorRouteAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (rotatedAtBreadVendor)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 170, 0));

		rotatedAtBreadVendor = false;
	}

	if (rotatedAtFruitVendor)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -162, 0));

		rotatedAtFruitVendor = false;
	}

	if (rotatedAtMeatVendor)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -129, 0));

		rotatedAtMeatVendor = false;
	}

	if (rotatedAtVegetableVendor)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -50, 0));

		rotatedAtVegetableVendor = false;
	}

	if (rotatedAtDrinksVendor)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -7, 0));

		rotatedAtDrinksVendor = false;
	}

	if (rotatedAtPantry)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 106, 0));

		rotatedAtPantry = false;
	}

	if (rotatedAtHouseTen)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 73, 0));

		rotatedAtHouseTen = false;
	}

	if (rotatedAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -97, 0));

		rotatedAtBed = false;
	}
}
