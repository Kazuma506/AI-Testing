#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sets base Max health
	MaxHealth = 100;

	//Sets base health
	Health = 100;

	//Sets base Max Stamina
	MaxStamina = 100;

	//Sets base Stamina
	Stamina = 100;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABaseCharacter::GetMaxHealth() const
{
	return MaxHealth;
}

float ABaseCharacter::GetHealth() const
{
	return Health;
}

bool ABaseCharacter::IsAlive() const
{
	return Health <= 0;
}

float ABaseCharacter::GetMaxStamina() const
{
	return MaxStamina;
}

float ABaseCharacter::GetStamina() const
{
	return Stamina;
}

float ABaseCharacter::IllnessModifier() const
{
	return Stamina;
}

float ABaseCharacter::GoodOrEvil() const
{
	return GoodOrEvilModifier;
}

int ABaseCharacter::GetWealth()
{
	return Wealth;
}

void ABaseCharacter::SetJob(FString Job)
{
	JobTitle = Job;
}

FString ABaseCharacter::GetJob()
{
	return JobTitle;
}

void ABaseCharacter::SetJobIncome(int Income)
{
	JobIncome = Income;
}

float ABaseCharacter::GetJobIncome()
{
	return JobIncome;
}

