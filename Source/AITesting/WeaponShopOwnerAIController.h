// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "WeaponShopOwnerAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API AWeaponShopOwnerAIController : public AAIController
{
	GENERATED_BODY()
public:
	AWeaponShopOwnerAIController();

	virtual void Possess(APawn *InPawn) override;
	void Tick(float DeltaTime);
	void MoveToCounter();
	void MoveToTableSection1();
	void MoveToTableSection2();
	void MoveToChair();
	void MoveToTableSection3();
	void MoveToTableSection4();
	void MoveToBed();
	void VillagerBehavior();
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);

	bool atCounter;
	bool atTableSection1;
	bool atTableSection2;
	bool atChair;
	bool atTableSection3;
	bool atTableSection4;
	bool atBed;

	bool rotatedAtCounter;
	bool rotatedAtTableSection1;
	bool rotatedAtTableSection2;
	bool rotatedAtChair;
	bool rotatedAtTableSection3;
	bool rotatedAtTableSection4;
	bool rotatedAtBed;

	bool destination1;
	bool destination2;
	bool destination3;
	bool destination4;
	bool destination5;
	bool destination6;
	bool destination7;

	float timeAtCounter;
	float timeAtTableSection1;
	float timeAtTableSection2;
	float timeAtChair;
	float timeAtTableSection3;
	float timeAtTableSection4;
	float timeAtBed;

	FTimerHandle positionSwitchingHandle;

	const FVector counterLocation = FVector(6720.0, 1310.0, 1260.0); // Counter Location
	const FVector tableSecton1Location = FVector(6620.0, 1020.0, 1260.0); // Table Section 1 Location
	const FVector tableSecton2Location = FVector(6620.0, 820.0, 1260.0); // Table Section 2 Location
	const FVector chairLocation = FVector(6970.0, 1290.0, 1260.0); // Chair Location
	const FVector tableSecton3Location = FVector(7080.0, 810.0, 1260.0); // Table Section 3 Location
	const FVector tableSecton4Location = FVector(7110.0, 1000.0, 1260.0); // Table Section 4 Location
	const FVector bedLocation = FVector(7030.0, 1320.0, 1260.0); // Bed Location
};
