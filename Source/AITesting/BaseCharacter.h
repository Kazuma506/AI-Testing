// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class AITESTING_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

public:
	/***************
	Health
	****************/

	UFUNCTION(BlueprintCallable, Category = "VillagerCondition")
		float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "VillagerCondition")
		float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "VillagerCondition")
		bool IsAlive() const;

	UPROPERTY(EditAnywhere, Category = "VillagerCondition")
		float Health;

	UPROPERTY(EditAnywhere, Category = "VillagerCondtion")
		float MaxHealth;

	/***************
	Stamina
	****************/

	UFUNCTION(BlueprintCallable, Category = "VillagerCondition")
		float GetMaxStamina() const;

	UFUNCTION(BlueprintCallable, Category = "VillagerCondition")
		float GetStamina() const;

	UPROPERTY(EditAnywhere, Category = "VillagerCondition")
		float Stamina;

	UPROPERTY(EditAnywhere, Category = "VillagerCondition")
		float MaxStamina;


	/***************
	Illness
	****************/

	UFUNCTION(BlueprintCallable, Category = "VillagerCondition")
		float IllnessModifier() const;

	/***************
	Good Or Evil
	****************/

	UFUNCTION(BlueprintCallable, Category = "VillagerCondition")
		float GoodOrEvil() const;

	UPROPERTY(EditAnywhere, Category = "VillagerCondition")
		float GoodOrEvilModifier;

	/***************
	Wealth
	****************/

	UFUNCTION(BlueprintCallable, Category = "VillagerInventory")
		int GetWealth();

	UPROPERTY(EditAnywhere, Category = "VillagerInventory")
		int Wealth;

	/***************
	Job
	****************/

	UFUNCTION(BlueprintCallable, Category = "VillagerJob")
		FString GetJob();

	UFUNCTION(BlueprintCallable, Category = "VillagerJob")
		float GetJobIncome();

	UFUNCTION(BlueprintCallable, Category = "VillagerJob")
		void SetJobIncome(int Income);

	UFUNCTION(BlueprintCallable, Category = "VillagerJob")
		void SetJob(FString Job);

	UPROPERTY(EditAnywhere, Category = "VillagerJob")
		FString JobTitle;

	UPROPERTY(EditAnywhere, Category = "VillagerJob")
		int JobIncome;


	/***************
	Behavior Tree & Blackboard
	****************/
	UPROPERTY(EditAnywhere, Category = "AI")
		class UBehaviorTree* VillagerBT;

	//UPROPERTY(EditAnywhere, Category = "AI")
	//class UBlackboardComponent* BlackboardComp;

	//UPROPERTY(EditAnywhere, Category = "AI")
	//class UBlackboard* Blackboard;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName Home;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
