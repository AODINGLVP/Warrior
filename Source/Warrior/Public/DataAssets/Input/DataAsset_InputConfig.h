// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Categories="InputTag"))
	FGameplayTag InputTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* InputAction;
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* DefultMappingContext;


	UPROPERTY(EditAnywhere, BlueprintReadOnly,meta=(TitleProerty="InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
	
};
