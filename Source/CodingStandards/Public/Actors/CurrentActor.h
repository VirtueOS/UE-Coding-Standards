// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>

#include "CurrentActor.generated.h"


DEFINE_LOG_CATEGORY_STATIC(LogCurrentActor, All, All);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHiddenInGame, AActor*, This, bool, bIsHidden);

class AOtherActor;
class UOtherComponent;

/**
 * CurrentActor is used as an example of code structure
 */
UCLASS()
class CODINGSTANDARDS_API ACurrentActor : public AActor
{
	GENERATED_BODY()

public:
	ACurrentActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	//~ Begin AActor
	virtual void SetActorHiddenInGame(bool bNewHidden) override;
	//~ End AActor

protected:
	//~ Begin AActor
	/** The comment should explain why the function was overridden or what it does  */
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~ End AActor

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UOtherComponent* GetOtherComponent() const { return OtherComponent; }

protected:
	UPROPERTY(BlueprintAssignable)
	FOnHiddenInGame OnHiddenInGame;

protected:
	UPROPERTY()
	TArray<TObjectPtr<AOtherActor>> RelevantActors;

	UPROPERTY(EditAnywhere, Category = Components)
	TObjectPtr<UOtherComponent> OtherComponent;
};