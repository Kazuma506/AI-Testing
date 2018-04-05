// Fill out your copyright notice in the Description page of Project Settings.

#include "AIBreadVendor.h"


// Sets default values
AAIBreadVendor::AAIBreadVendor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIBreadVendor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIBreadVendor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIBreadVendor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

