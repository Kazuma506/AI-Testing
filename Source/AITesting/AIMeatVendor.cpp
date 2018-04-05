// Fill out your copyright notice in the Description page of Project Settings.

#include "AIMeatVendor.h"


// Sets default values
AAIMeatVendor::AAIMeatVendor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIMeatVendor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIMeatVendor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIMeatVendor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

