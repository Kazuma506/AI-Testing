// Fill out your copyright notice in the Description page of Project Settings.

#include "NewAISystemExperiment.h"

ANewAISystemExperiment::ANewAISystemExperiment()
{
	//locationNames.Add(TEXT("Blacksmith Shop"));

//	locations.Add(FVector(5090, -700, 1260));

	arrayPosition = 0;
}

 void ANewAISystemExperiment::MoveToDestination(FString Destination)
{
	

	 for (int i = 0; i > 1; i++)
	 {
		 if (Destination.IsEmpty())
		 {
			 UE_LOG(LogTemp, Warning, TEXT("Destination Does not exist"));
			 break;
		 }

		 if (Destination == locationNames[i])
		 {
			 arrayPosition = i;
			 break;
		 }

	 }
	 if (arrayPosition != NULL)
	 {
	 }
}
