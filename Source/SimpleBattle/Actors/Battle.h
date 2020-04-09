// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Pawns/Unit.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Battle.generated.h"

UENUM(BlueprintType)
enum class EBattleStages : uint8 {
	Beginning,
	SelectingAction,
	PlayingActions,
	CheckingBattleStatus,
	Ending
};


UCLASS()
class SIMPLEBATTLE_API ABattle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Units", meta=(AllowPrivateAccess="true"))
	TArray<AUnit*> Allies;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Units", meta = (AllowPrivateAccess = "true"))
	TArray<AUnit*> Enemies;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Units", meta = (AllowPrivateAccess = "true"))
	TArray<AUnit*> AllUnits;

	// This is the index of the unit whose currently playing an action of selection one.
	UPROPERTY()
	int16 UnitTurnIndex = 0;

	EBattleStages CurrentStage = EBattleStages::Beginning;

	bool IsUnitSelecting = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Result", meta = (AllowPrivateAccess = "true"))
	FString Winner;

	bool DidTheBattleEnded();

	//Cycle
	void ActionSelection();
	void DisplayActions();
	void DisplayResultScreen();



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void SetupBattleUI();

	UFUNCTION()
	void MoveToNextTurn();

};
