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
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats", meta=(DisplayName="Health"))
		int32 HealthPoints;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats", meta = (DisplayName = "Attack"))
		int32 AttackPoints;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats", meta = (DisplayName = "Defense"))
		int32 DefensePoints;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Stats", meta = (DisplayName = "Speed"))
		int32 SpeedPoints;

};
