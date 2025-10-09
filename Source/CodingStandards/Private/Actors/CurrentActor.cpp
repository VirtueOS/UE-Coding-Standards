// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/CurrentActor.h"

#if WITH_EDITOR
#include <Misc/DataValidation.h>
#endif

#include UE_INLINE_GENERATED_CPP_BY_NAME(CurrentActor)

ACurrentActor::ACurrentActor(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACurrentActor::SetActorHiddenInGame(const bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	OnHiddenInGame.Broadcast(this, bNewHidden);
}

void ACurrentActor::PostInitProperties()
{
	Super::PostInitProperties();
}

#if WITH_EDITOR
EDataValidationResult ACurrentActor::IsDataValid(class FDataValidationContext& Context) const
{
	return Super::IsDataValid(Context);
}
//# [comment.endif] It is better to add a comment indicating #endif condition, but it's okay to leave it empty
#endif // WITH_EDITOR

void ACurrentActor::BeginPlay()
{
	Super::BeginPlay();

	Speed = 1.0f;
}

void ACurrentActor::SetOtherComponent(UOtherComponent* NewOtherComponent)
{
	OtherComponent = NewOtherComponent;
}

void ACurrentActor::OnRep_OtherComponent()
{
}