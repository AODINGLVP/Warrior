// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "WarriorEnemyWave.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorEnemyWave : public UDataAsset
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FEnemyWave> Waves;
	
};
