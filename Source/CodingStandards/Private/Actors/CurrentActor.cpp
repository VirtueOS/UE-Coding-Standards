// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/CurrentActor.h"

ACurrentActor::ACurrentActor(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACurrentActor::SetActorHiddenInGame(const bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	OnHiddenInGame.Broadcast(this, bNewHidden);
}

void ACurrentActor::BeginPlay()
{
	Super::BeginPlay();
}

void ACurrentActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}