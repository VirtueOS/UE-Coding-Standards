// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/CurrentActor.h"

#include <Net/Core/PushModel/PushModel.h>
#include <Net/UnrealNetwork.h>

#if WITH_EDITOR
#include <Misc/DataValidation.h>
#endif

//# [include.inline] Always add UE_INLINE_GENERATED_CPP_BY_NAME in cpp
#include UE_INLINE_GENERATED_CPP_BY_NAME(CurrentActor)

DEFINE_LOG_CATEGORY_STATIC(LogCurrentActor, All, All);

ACurrentActor::ACurrentActor(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACurrentActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//# [replication.push] Prefer to use PushBased
	FDoRepLifetimeParams SharedParams;
	SharedParams.bIsPushBased = true;

	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, OtherComponent, SharedParams);
}

void ACurrentActor::SetActorHiddenInGame(const bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	OnHiddenInGame.Broadcast(this, bNewHidden);
}

//# [function.useless]
//# Remove functions that serve no purpose and only call their parent implementations
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
	//# [if.guard] Prefer to use guard clause, but a regular if is acceptable for a single level of nesting
	if (OtherComponent || !NewOtherComponent)
	{ //# [if.braces] Always use braces, even for single-line statements
		return;
	}
		
	if (HasAuthority())
	{
		OtherComponent = NewOtherComponent;
		//# [replication.push.dirty] Don't forget to manually mark property dirty for PushBased replication
		MARK_PROPERTY_DIRTY_FROM_NAME(ACurrentActor, OtherComponent, this);
	}
}

void ACurrentActor::OnRep_OtherComponent()
{
}