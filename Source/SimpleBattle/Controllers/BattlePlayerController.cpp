// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actors/Battle.h"
#include "BattlePlayerController.h"
#include <Kismet/GameplayStatics.h>
#include "Engine/World.h"
#include "../Pawns/BattlePlayerPawn.h"

void ABattlePlayerController::BeginPlay()
{
	Super::BeginPlay();
	BattlePtr = Cast<ABattle>(UGameplayStatics::GetActorOfClass(GetWorld(), ABattle::StaticClass()));
	EnemyCount = BattlePtr->GetEnemyCount();
	BPPptr = Cast<ABattlePlayerPawn>(GetPawn());
}

const int32 MENU_INDEX_MAX = 2;

void ABattlePlayerController::IncrementMenuIndex()
{
	if (!BPPptr->CanAct() && !bIsSelectingMenuOptions)return;
	MenuIndex = FMath::Clamp(MenuIndex + 1, 0, MENU_INDEX_MAX);
}

void ABattlePlayerController::DecrementMenuIndex()
{
	if (!BPPptr->CanAct() && !bIsSelectingMenuOptions)return;
	MenuIndex = FMath::Clamp(MenuIndex - 1, 0, MENU_INDEX_MAX);
}

void ABattlePlayerController::IncrementEnemyIndex()
{
	if (!BPPptr->CanAct() && bIsSelectingMenuOptions)return;
	EnemyIndex = FMath::Clamp(EnemyIndex + 1, 0, EnemyCount-1);
}

void ABattlePlayerController::DecrementEnemyIndex()
{
	if (!BPPptr->CanAct() && bIsSelectingMenuOptions)return;
	EnemyIndex = FMath::Clamp(EnemyIndex - 1, 0, EnemyCount - 1);
}

void ABattlePlayerController::SelectMenuOption()
{
	if (!BPPptr->CanAct() && !bIsSelectingMenuOptions)return;
	switch (MenuIndex)
	{
	case 0://Attack
		BPPptr->AppendActionString("Attack", false);
		bIsSelectingMenuOptions = false;
		break;
	case 1:// Defend
		BPPptr->AppendActionString("Defend", false);
		BPPptr->SendActionToUnit();
		ResetVariables();
		break;
	case 2://Escape
		BPPptr->AppendActionString("Escape", false);
		BPPptr->SendActionToUnit();
		ResetVariables();
	default:
		UE_LOG(LogTemp, Error, TEXT("The menu index cannot be greater than 2"));
		break;
	}
}

void ABattlePlayerController::SelectEnemyOption()
{
	if (!BPPptr->CanAct() && bIsSelectingMenuOptions)return;
	if (!BattlePtr->IsEnemyAlive(EnemyIndex)) return;
	BPPptr->AppendActionString(FString::FromInt(EnemyIndex));
	BPPptr->SendActionToUnit();
	ResetVariables();
}

void ABattlePlayerController::ResetVariables()
{
	EnemyIndex = 0;
	MenuIndex = 0;
	bIsSelectingMenuOptions = true;
}
