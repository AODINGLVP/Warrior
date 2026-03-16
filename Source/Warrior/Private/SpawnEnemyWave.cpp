// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEnemyWave.h"

#include "DataAssets/EnemyWave/WarriorEnemyWave.h"


// Sets default values
ASpawnEnemyWave::ASpawnEnemyWave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnEnemyWave::BeginPlay()
{
	Super::BeginPlay();
	if (EnemyWaveData)
	{
		
	}
}

// Called every frame
void ASpawnEnemyWave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckEnemyAlive();

}

void ASpawnEnemyWave::SpawnEnemy()
{
	if (EnemyWaveCount < EnemyWaveData->Waves.Num()) {
		
			for (int i = 0; i < EnemyWaveData->Waves[EnemyWaveCount].Enemies.Num();i++) {
			
				for (int j = 0; j < EnemyWaveData->Waves[EnemyWaveCount].Enemies[i].Count; j++) {
					FActorSpawnParameters SpawnParameters;
					SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;



					 RandomX = FMath::FRandRange(-SpawnRadius, SpawnRadius);
					 RandomY = FMath::FRandRange(-SpawnRadius, SpawnRadius);

					 SpawnLocation = Origin + FVector(RandomX, RandomY, 0.f);


					 AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(
						 EnemyWaveData->Waves[EnemyWaveCount].Enemies[i].EnemyClass,
						 SpawnLocation,
						 GetActorRotation(),
						 SpawnParameters
					 );
					if (SpawnedActor)
					{
						Enemies.Add(SpawnedActor);
						SpawnedActor->OnDestroyed.AddDynamic(this, &ASpawnEnemyWave::HandleEnemyDestroyed);
					}
					else
					{
						UE_LOG(LogTemp, Error, TEXT("SpawnActor failed"));
					}

			}
			
			}
			
		
	}
	EnemyWaveCount++;

}

void ASpawnEnemyWave::CheckEnemyAlive()
{
	if (Enemies.Num() == 0) {
		
		SpawnEnemy();
	}
}

void ASpawnEnemyWave::HandleEnemyDestroyed(AActor* DestroyedActor)
{
	if (!DestroyedActor)
	{
		return;
	}

	Enemies.Remove(DestroyedActor);
	

	
}