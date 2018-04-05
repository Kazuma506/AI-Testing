// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AITestingGameMode.h"
#include "AITestingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAITestingGameMode::AAITestingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AAITestingGameMode::Tick(float DeltaTime)
{
	GetWorldTimerManager().SetTimer(timeHandler, this, &AAITestingGameMode::AddToTime, 60, true);
}

void AAITestingGameMode::AddToTime()
{
	time++;
}

int AAITestingGameMode::GetTimeofDay()
{
	return time;
}
