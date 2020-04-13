// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BattlePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEBATTLE_API ABattlePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="HUD Controller")
	void IncrementMenuIndex();
	UFUNCTION(BlueprintCallable, Category = "HUD Controller")
	void DecrementMenuIndex();
	UFUNCTION(BlueprintCallable, Category = "HUD Controller")
	void IncrementEnemyIndex();
	UFUNCTION(BlueprintCallable, Category = "HUD Controller")
	void DecrementEnemyIndex();
	UFUNCTION(BlueprintCallable, Category = "HUD Controller")
	void SelectMenuOption();
	UFUNCTION(BlueprintCallable, Category = "HUD Controller")
	void SelectEnemyOption();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI|Index", meta=(AllowPrivateAccess="true"))
	int32 MenuIndex = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI|Index", meta = (AllowPrivateAccess = "true"))
	int32 EnemyIndex = 0;
	// How many enemies are in battle
	int32 EnemyCount = 0;

	class ABattlePlayerPawn* BPPptr = nullptr;

	class ABattle* BattlePtr = nullptr;

	void ResetVariables();

	UPROPERTY(BlueprintReadOnly, Category="HUD Boolean", meta=(AllowPrivateAccess="true"))
	bool bIsSelectingMenuOptions = true;
};
