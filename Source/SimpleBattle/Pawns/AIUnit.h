// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "AIUnit.generated.h"

/**
 * 
 */
UCLASS(HideCategories = ("Camera", "Rendering", "Replication", "LOD", "Cooking", "Actor Tick"))
class SIMPLEBATTLE_API AAIUnit : public AUnit
{
	GENERATED_BODY()

public:

	virtual bool IsAnEnemy() const override;
	
};
