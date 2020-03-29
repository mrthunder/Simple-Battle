// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit.h"
#include <Kismet/KismetMathLibrary.h>
#include "../Actors/Battle.h"

// Sets default values
AUnit::AUnit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentHealth = Stats.HealthPoints;
}



// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

int32 AUnit::ReduceCurrentHealth(int32 amount)
{
	// I am calculating the max amount that the health can be deductible
//	it cannot be greater than the current health or lower than zero
	int32 DeductibleAmount = FMath::Clamp(amount, 0, CurrentHealth);
	CurrentHealth -= DeductibleAmount;
	return DeductibleAmount;
}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AUnit::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	return UKismetMathLibrary::Conv_IntToFloat(ReduceCurrentHealth(Damage));;
}

int32 AUnit::GetCurrentHealth() const
{
	return CurrentHealth;
}

void AUnit::SetCurrentHealth(int amount)
{
	int CorrectedAmount = FMath::Clamp(amount, 0, Stats.HealthPoints);
	CurrentHealth = CorrectedAmount;
}

float AUnit::GetHealthPercentage() const
{
	return UKismetMathLibrary::Conv_IntToFloat(CurrentHealth) /
		Stats.HealthPoints;
}


void AUnit::ChooseAction_Implementation(const ABattle* BattleRef)
{
	UE_LOG(LogTemp, Warning, TEXT("The function %s was not implemented"), *__FUNCTION__)
}

