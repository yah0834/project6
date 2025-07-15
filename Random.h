// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Random.generated.h"

UCLASS()
class ARandom : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARandom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<FVector> GenerateRandomLocation();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(EditAnywhere)
	FIntPoint GridSize;

	UPROPERTY(EditAnywhere)
	int SpawnCount;

	UPROPERTY(EditAnywhere)
	float SpawnOffset;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> ActorClassToSpawn;
};
