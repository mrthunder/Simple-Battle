// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGStats.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct SIMPLEBATTLE_API FRPGStats
{
    GENERATED_USTRUCT_BODY()
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Values")
		int32 MaxHealth;
	UPROPERTY(BlueprintReadWrite, Category = "Values")
		int32 CurrentHealth;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Values")
		int32 AttackPoints;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Values")
		int32 DefensePoints;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Values")
		int32 SpeedPoints;

};
