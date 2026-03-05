// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	int scv = 0;

	template<class UserObject,typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func) {
		//check(InInputConfig);
		checkf(InInputConfig, TEXT("input in null"));
		if (UInputAction* FoundAction=InInputConfig->FindNativeInputActionByTag(InInputTag)) {
			BindAction(FoundAction, TriggerEvent, ContextObject, Func);
			scv++;
			UE_LOG(LogTemp, Warning, TEXT("scv=%d"),scv);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("BindAction failed: %s"),
				*InInputTag.ToString());
		}

	}


	
};
