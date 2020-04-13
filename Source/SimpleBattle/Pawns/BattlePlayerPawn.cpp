// Fill out your copyright notice in the Description page of Project Settings.

#include "Unit.h"
#include "BattlePlayerPawn.h"

// Sets default values
ABattlePlayerPawn::ABattlePlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattlePlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	for (size_t i = 0; i < PlayerUnits.Num();i++)
	{
		PlayerUnits[i]->StartTurn.AddDynamic(this, &ABattlePlayerPawn::StartSelectingAction);
	}
}

// Called every frame
void ABattlePlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattlePlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABattlePlayerPawn::StartSelectingAction(AUnit* unit)
{
	if(IsValid(unit))
	{
		int32 indexOf = PlayerUnits.IndexOfByKey(unit);
		if (indexOf != INDEX_NONE)
		{
			IndexofCurrentUnit = indexOf;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("The playable unit is not known by the BPP."));
		}
	}
}

void ABattlePlayerPawn::AppendActionString(FString action, bool bWithPrefix)
{
	if (IndexofCurrentUnit == INDEX_NONE) return;
	if (bWithPrefix)
	{
		ActionBuilder.Append(" > " + action);
	}
	else
	{
		ActionBuilder.Append(action);
	}
	
}

void ABattlePlayerPawn::RemoveActionFromString(FString action)
{
	if (IndexofCurrentUnit == INDEX_NONE) return;
	int32 StartIndex = ActionBuilder.Find(" > " + action);
	if (ActionBuilder.IsValidIndex(StartIndex))
	{
		// 3 is from the " > "
		ActionBuilder.RemoveAt(StartIndex, action.Len() + 3);
	}
	else
	{
		StartIndex = ActionBuilder.Find(action);
		if (ActionBuilder.IsValidIndex(StartIndex))
		{
			ActionBuilder.RemoveAt(StartIndex, action.Len());
		}
	}
}

void ABattlePlayerPawn::SendActionToUnit()
{
	PlayerUnits[IndexofCurrentUnit]->SetAction(ActionBuilder);
	IndexofCurrentUnit = INDEX_NONE;
	ActionBuilder = "";
}

bool ABattlePlayerPawn::CanAct()
{
	return IndexofCurrentUnit != INDEX_NONE;
}

