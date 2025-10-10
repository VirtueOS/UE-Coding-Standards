//# [comment.documentation]
//# In order to distinguish documentation comments from regular code comments, documentation will use the //# prefix

//# [basic.language]
//# Use US English for all names and comments
//# BAD -> FColor SpecialisedColour;
//# GOOD -> FColor SpecializedColor;

//# [header.copyright] Leave default copyright notice on top
// Fill out your copyright notice in the Description page of Project Settings.

//# [header.guard] Always add '#pragma once' on top
#pragma once

//# [header.include.core] CoreMinimal.h is always listed on top
#include <CoreMinimal.h>

//# [header.include.engine] All Engine files should use angle brackets
#include <GameFramework/Actor.h>

//# [header.include.project] All Project files should use quotes
//# [header.include.path] Use full relative path for includes
// BAD-> #include <OtherActor.h>
// BAD-> #include "OtherActor.h"
// GOOD -> #include "Actors/OtherActor.h"

//# [header.include.generated] generated.h must be last in include list
#include "CurrentActor.generated.h"

//# [header.include.settings]
//# Include sorting handled by clang-format
//# Brackets and Path rules could be enforced via rider settings
//# Make sure to set up both of them

//# [header.fwd] Prefer to use forward declaration if possible
class AOtherActor;
class UOtherComponent;

//# [header.api]
//# Starting with UE5 Epics redefining module api to UE_API to simplify moving classes between modules
//# Don't forget to undef it at the bottom of the file
#define UE_API CODINGSTANDARDS_API

DEFINE_LOG_CATEGORY_STATIC(LogCurrentActor, All, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHiddenInGame, AActor*, This, bool, bIsHidden);

//# [comment.doxygen] Use /// comments for classes, functions, and variables descriptions to generate Doxygen documentation
/// ACurrentActor is used as an example of coding standards
UCLASS()
class UE_API ACurrentActor : public AActor
{
	GENERATED_BODY()

	//# [header.class.structure]
	//# Class structure should be as follows:
	//# 1. Constructors
	//# 2. Functions
	//# 3. Template Functions
	//# 4. Getters/Setters
	//# 5. OnRep_
	//# 6. Delegates
	//# 7. Variables
	//#
	//# Each section should go from public to protected to private
	//# Each section could be divided into smaller sections (e.g. functions divided into team/gas/inventory/...)
	//# However, the need for divisions indicates that the class should be decomposed

	//# 1. Constructors
public:
	ACurrentActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//# 2. Functions
public:
	//# [comment.override] Mark override sections with //~ Begin/End CLASS_NAME
	//~ Begin AActor
	virtual void SetActorHiddenInGame(bool bNewHidden) override;
	//~ End AActor

	//~ Begin UObject
	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
	//~ End UObject

protected:
	//~ Begin AActor
	//# [comment.useless] Comment should explain the purpose or usage of the code
	/// BAD -> Overrides BeginPlay of AActor
	virtual void BeginPlay() override;
	//~ End AActor

	//# 4. Getters/Setters
public:
	//# [header.inline] only trivial functions should be inline
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UOtherComponent* GetOtherComponent() const { return OtherComponent; }

	void SetOtherComponent(UOtherComponent* NewOtherComponent);

	//# 5. OnRep_
public:
	UFUNCTION()
	void OnRep_OtherComponent();

	//# 6. Delegates
protected:
	UPROPERTY(BlueprintAssignable)
	FOnHiddenInGame OnHiddenInGame;

	//# 7. Variables
protected:
	UPROPERTY()
	TArray<TWeakObjectPtr<AOtherActor>> RelevantActors;

	UPROPERTY(EditAnywhere, Category = Components, ReplicatedUsing = "OnRep_OtherComponent")
	TObjectPtr<UOtherComponent> OtherComponent = nullptr;

	//# [basic.float] always add .0f
	float Speed = 0.0f;

	//# [basic.bool] should start with 'b' followed by modal verb (Can, Does, Will, Is, Has, ...)
	bool bIsInitialized = false;
};

//# [header.api] Don't forget to undef!
#undef UE_API
