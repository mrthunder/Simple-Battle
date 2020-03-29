// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableUnit.h"

APlayableUnit::APlayableUnit()
{
	//Make sure that no controller will posses this pawn.
	AIControllerClass = nullptr;
	AutoPossessAI = EAutoPossessAI::Disabled;
}
