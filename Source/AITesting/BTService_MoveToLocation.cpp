// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_MoveToLocation.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIVillager.h"
#include "VillagerAIController.h"


UBTService_MoveToLocation::UBTService_MoveToLocation()
{
	bCreateNodeInstance = true;

	BlacksmithShopLocation = FVector(5210.0, -840.0, 1260.0);


}

void UBTService_MoveToLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// Grabs AI Controller class
	AAIVillager *VillagerController = Cast<AAIVillager>(OwnerComp.GetAIOwner());


}




