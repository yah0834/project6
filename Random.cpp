// Fill out your copyright notice in the Description page of Project Settings.


#include "Random.h"

// Sets default values
ARandom::ARandom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GridSize = FIntPoint(1, 1);
	SpawnCount = 1;
	SpawnOffset = 500.f;
}

// Called when the game starts or when spawned
void ARandom::BeginPlay()
{
	Super::BeginPlay();


	TArray<FVector> Locations = GenerateRandomLocation();

	// 방어 코드: ActorClassToSpawn이 비어있는 경우
	if (ActorClassToSpawn.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorClassToSpawn 배열이 비어 있습니다."));
		return;
	}

	// 방어 코드: 생성 위치가 없는 경우
	if (Locations.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("GenerateRandomLocation()이 빈 배열을 반환했습니다."));
		return;
	}

	// 방어 코드: SpawnCount가 위치 수보다 많을 경우 조정
	if (SpawnCount > Locations.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnCount(%d)가 Locations 수(%d)보다 많아 조정됩니다."), SpawnCount, Locations.Num());
		SpawnCount = Locations.Num();
	}

	for (size_t i = 0; i < SpawnCount; ++i)
	{
		int LocationIndex = FMath::RandRange(0, Locations.Num() - 1);

		FVector SpawnLocation = Locations[LocationIndex];

		int ActorIndex = FMath::RandRange(0, ActorClassToSpawn.Num() - 1);

		GetWorld()->SpawnActor<AActor>(
			ActorClassToSpawn[ActorIndex],
			SpawnLocation,
			FRotator::ZeroRotator);

		Locations.RemoveAt(LocationIndex);
	}

}

TArray<FVector> ARandom::GenerateRandomLocation()
{

	TArray<FVector> Locations;

	for (size_t Row = 0; Row < GridSize.X; ++Row)
	{
		for (size_t Column = 0; Column < GridSize.Y; ++Column)
		{
			float X = Row * SpawnOffset;
			float Y = Column * SpawnOffset;

			Locations.Add(FVector(X, Y, GetActorLocation().Z));
		}
	}

	return Locations;
}

// Called every frame
void ARandom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

