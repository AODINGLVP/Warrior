// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "SpawnEnemyWave.generated.h"
class UWarriorEnemyWave;
UCLASS()
class WARRIOR_API ASpawnEnemyWave : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnEnemyWave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void HandleEnemyDestroyed(AActor* DestroyedActor);
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave")
	UWarriorEnemyWave* EnemyWaveData;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void SpawnEnemy();
	void CheckEnemyAlive();
	TArray<AActor*> Enemies;
	int EnemyWaveCount=0;
	TArray<FEnemyWave*> Waves;
	float SpawnRadius = 750.f; // 随机范围

	FVector Origin = GetActorLocation();

	float RandomX = FMath::FRandRange(-SpawnRadius, SpawnRadius);
	float RandomY = FMath::FRandRange(-SpawnRadius, SpawnRadius);

	FVector SpawnLocation = Origin + FVector(RandomX, RandomY, 0.f);

};
