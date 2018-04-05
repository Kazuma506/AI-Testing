// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_MoveToLocation.generated.h"

/**
 * 
 */
UCLASS()
class AITESTING_API UBTService_MoveToLocation : public UBTService
{
	GENERATED_BODY()
	
public:

	UBTService_MoveToLocation();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	FVector BlacksmithShopLocation;




};
