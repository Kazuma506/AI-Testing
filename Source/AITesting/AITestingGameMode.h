// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimerManager.h"
#include "AITestingGameMode.generated.h"

UCLASS(minimalapi)
class AAITestingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAITestingGameMode();
	void Tick(float DeltaTime);
	void AddToTime();
	int GetTimeofDay();

	int time;
	
	FTimerHandle timeHandler;

};



