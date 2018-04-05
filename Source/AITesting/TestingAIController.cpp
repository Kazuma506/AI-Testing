// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingAIController.h"
#include "NewAISystemExperiment.h"

ATestingAIController::ATestingAIController()
{

}
void ATestingAIController::Tick(float DeltaTime)
{
	ANewAISystemExperiment* MoveAI = Cast<ANewAISystemExperiment>(GetClass());

	//UE_LOG(LogTemp, Warning, TEXT("Yo"));
	
	MoveAI->MoveToDestination("Blacksmith Shop");
	//MoveToLocation(locations[MoveAI->], 1.0f);
}
