// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponShopOwnerAIController.h"
#include "AIVillager.h"
#include "TimerManager.h"

AWeaponShopOwnerAIController::AWeaponShopOwnerAIController()
{
	atCounter = false;
	atTableSection1 = true;
	atTableSection2 = false;
	atChair = false;
	atTableSection3 = false;
	atTableSection4 = false;
	atBed = false;

	rotatedAtCounter = false;
	rotatedAtTableSection1 = true;
	rotatedAtTableSection2 = false;
	rotatedAtChair = false;
	rotatedAtTableSection3 = false;
	rotatedAtTableSection4 = false;
	rotatedAtBed = false;

	destination1 = false;
	destination2 = true;
	destination3 = false;
	destination4 = false;
	destination5 = false;
	destination6 = false;
	destination7 = false;

	timeAtCounter = 660;
	timeAtTableSection1 = 40;
	timeAtTableSection2 = 40;
	timeAtChair = 40;
	timeAtTableSection3 = 30;
	timeAtTableSection4 = 30;
	timeAtBed = 400;
}

void AWeaponShopOwnerAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
}

void AWeaponShopOwnerAIController::Tick(float DeltaTime)
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
		MoveToLocation(tableSecton1Location, 1.0f);

		atTableSection1 = true;

		destination2 = false;
	}

	if (destination3)
	{
		MoveToLocation(tableSecton2Location, 1.0f);

		atTableSection2 = true;

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
		MoveToLocation(tableSecton3Location, 1.0f);

		atTableSection3 = true;

		destination5 = false;
	}

	if (destination6)
	{
		MoveToLocation(tableSecton4Location, 1.0f);

		atTableSection4 = true;

		destination6 = false;
	}

	if (destination7)
	{
		MoveToLocation(bedLocation, 1.0f);

		atBed = true;

		destination7 = false;
	}
}

void AWeaponShopOwnerAIController::MoveToCounter()
{
	destination1 = true;

	rotatedAtCounter = true;
}

void AWeaponShopOwnerAIController::MoveToTableSection1()
{
	destination2 = true;

	rotatedAtTableSection1 = true;

}

void AWeaponShopOwnerAIController::MoveToTableSection2()
{
	destination3 = true;

	rotatedAtTableSection2 = true;
}

void AWeaponShopOwnerAIController::MoveToChair()
{
	destination4 = true;

	rotatedAtChair = true;
}

void AWeaponShopOwnerAIController::MoveToTableSection3()
{
	destination5 = true;

	rotatedAtTableSection3 = true;
}

void AWeaponShopOwnerAIController::MoveToTableSection4()
{
	destination6 = true;

	rotatedAtTableSection4 = true;
}

void AWeaponShopOwnerAIController::MoveToBed()
{
	destination7 = true;

	rotatedAtBed = true;
}

void AWeaponShopOwnerAIController::VillagerBehavior()
{
	if (atTableSection1)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AWeaponShopOwnerAIController::MoveToTableSection2, timeAtTableSection1, false);

		atTableSection1 = false;
	}

	if (atTableSection2)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AWeaponShopOwnerAIController::MoveToChair, timeAtTableSection2, false);

		atTableSection2 = false;
	}

	if (atChair)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AWeaponShopOwnerAIController::MoveToTableSection3, timeAtChair, false);

		atChair = false;
	}

	if (atTableSection3)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AWeaponShopOwnerAIController::MoveToTableSection4, timeAtTableSection3, false);

		atTableSection3 = false;
	}

	if (atTableSection4)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AWeaponShopOwnerAIController::MoveToCounter, timeAtTableSection4, false);

		atTableSection4;
	}
	if (atCounter)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AWeaponShopOwnerAIController::MoveToBed, timeAtCounter, false);

		atCounter = false;
	}

	if (atBed)
	{
		GetWorldTimerManager().SetTimer(positionSwitchingHandle, this, &AWeaponShopOwnerAIController::MoveToTableSection1, timeAtBed, false);

		atBed = false;
	}
}

void AWeaponShopOwnerAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (rotatedAtCounter)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -90, 0));

		rotatedAtCounter = false;
	}

	if (rotatedAtTableSection1)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 170, 0));

		rotatedAtTableSection1 = false;
	}

	if (rotatedAtTableSection2)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -90, 0));

		rotatedAtTableSection2 = false;
	}

	if (rotatedAtChair)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -90, 0));

		rotatedAtChair = false;
	}

	if (rotatedAtTableSection3)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, -60, 0));

		rotatedAtTableSection3 = false;
	}

	if (rotatedAtTableSection4)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 0, 0));

		rotatedAtTableSection4 = false;
	}

	if (rotatedAtBed)
	{
		AAIVillager* AIChar = Cast<AAIVillager>(GetPawn());

		AIChar->SetActorRotation(FRotator(0, 0, 0));

		rotatedAtBed = false;
	}
}


