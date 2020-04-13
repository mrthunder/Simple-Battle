// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BattlePlayerPawn.generated.h"

class AUnit;

UCLASS()
class SIMPLEBATTLE_API ABattlePlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABattlePlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	int32 IndexofCurrentUnit = INDEX_NONE;

	FString ActionBuilder;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<AUnit*> PlayerUnits;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void StartSelectingAction(class AUnit* unit);

	void AppendActionString(FString action, bool bWithPrefix = true);

	void RemoveActionFromString(FString action);

	void SendActionToUnit();
	
	//This will tell if the controller can control the HUD to select the action
	bool CanAct();
	
};
