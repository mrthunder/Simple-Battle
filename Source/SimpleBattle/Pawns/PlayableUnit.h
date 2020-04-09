// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "PlayableUnit.generated.h"

/**
 * A playable unit is a unit that can be controllable by the player during battles.
 */
UCLASS(HideCategories=("Pawn", "Camera","Rendering","Replication","LOD","Cooking","Actor Tick"))
class SIMPLEBATTLE_API APlayableUnit : public AUnit
{
	GENERATED_BODY()
public:
    APlayableUnit();

	virtual void ChooseAction_Implementation(const FOnTurnEnd& turnCallback) override;
};
