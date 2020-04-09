// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "../Models/RPGStats.h"
#include "Unit.generated.h"


DECLARE_DYNAMIC_DELEGATE(FOnTurnEnd);

UCLASS()
class SIMPLEBATTLE_API AUnit : public APawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	AUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RPG")
	FRPGStats Stats = FRPGStats();

	UPROPERTY(VisibleInstanceOnly,BlueprintReadWrite, Category="Stats", meta=(BlueprintSetter="SetCurrentHealth",BlueprintGetter="GetCurrentHealth"))
	int32 CurrentHealth = 0;

	UFUNCTION()
	int32 ReduceCurrentHealth(int32 amount);

	UPROPERTY()
		FOnTurnEnd Callback;

public:	

	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32 GetCurrentHealth()const;
	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(int amount);
	// I am calculating how much health in percentage does the unit has
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHealthPercentage()const;

	UFUNCTION()
	FRPGStats GetStats()const;

	UFUNCTION(BlueprintNativeEvent, Category="RPG|Battle|Actions")
	void ChooseAction(const FOnTurnEnd& turnCallback);

	virtual void ChooseAction_Implementation(const FOnTurnEnd& turnCallback);

	virtual bool IsAnEnemy() const;

};
