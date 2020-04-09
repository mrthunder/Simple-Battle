// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle.h"

// Sets default values
ABattle::ABattle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattle::BeginPlay()
{
	Super::BeginPlay();
	//I am adding all the allies and enemies to the all units array.
	size_t maxLength = (Enemies.Num() > Allies.Num() ? Enemies.Num() : Allies.Num());
	for (size_t i = 0; i < maxLength; i++)
	{
		if (i < Enemies.Num())
		{
			AllUnits.Add(Enemies[i]);
		}
		if (i < Allies.Num())
		{
			AllUnits.Add(Allies[i]);
		}
	}
	// I am sorting based on the fastest.
	AllUnits.Sort([](auto& a, auto& b) -> bool {
		return a.GetStats().SpeedPoints < b.GetStats().SpeedPoints;
	});
	SetupBattleUI();
	CurrentStage = EBattleStages::SelectingAction;

}

bool ABattle::DidTheBattleEnded()
{
	auto AlliesResult = Allies.ContainsByPredicate([](AUnit* a) {
		return a->GetCurrentHealth() > 0;
	});
	if (AlliesResult)
	{
		Winner = "Enemies";
		return true;
	}
	auto EnemiesResult = Enemies.ContainsByPredicate([](AUnit* a) {
		return a->GetCurrentHealth() > 0;
	});
	if (EnemiesResult)
	{
		Winner = "Allies";
		return true;
	}
	return false;
}

void ABattle::ActionSelection()
{
	if (!IsUnitSelecting)
	{
		IsUnitSelecting = true;
		//AllUnits[UnitTurnIndex]->ChooseAction(FOnTurnEnd::CreateRaw(this,&ABattle::MoveToNextTurn));
	}
}

void ABattle::DisplayActions()
{
	// TODO: Create this function
}

void ABattle::DisplayResultScreen()
{
	// TODO: Create this function
}

// Called every frame
void ABattle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (CurrentStage)
	{
	case EBattleStages::SelectingAction:
		ActionSelection();
		break;
	case EBattleStages::PlayingActions:
		DisplayActions();
		break;
	case EBattleStages::CheckingBattleStatus:
		if (DidTheBattleEnded())
		{
			CurrentStage = EBattleStages::Ending;
		}
		else
		{
			if (UnitTurnIndex == 0)
			{
				CurrentStage = EBattleStages::SelectingAction;
			}
		}
		break;
	case EBattleStages::Ending:
		DisplayResultScreen();
		break;
	default:
		break;
	}

}

void ABattle::MoveToNextTurn()
{
	UnitTurnIndex++;
	if (IsUnitSelecting)
	{
		IsUnitSelecting = false;
	}
	if (UnitTurnIndex >= AllUnits.Num())
	{
		UnitTurnIndex = 0;
		if (CurrentStage == EBattleStages::SelectingAction)
		{
			CurrentStage = EBattleStages::PlayingActions;
		}
	}
	
}

