// Fill out your copyright notice in the Description page of Project Settings.


#include "rota.h"

// Sets default values
Arota::Arota()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	SetRootComponent(StaticMeshComp);

	RotSpeed = 50.f;
}

// Called when the game starts or when spawned
void Arota::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager();
}

// Called every frame
void Arota::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator DeltaRotation = FRotator(0.0f, 1.0f, 0.0f) * DeltaTime * RotSpeed;
	AddActorLocalRotation(DeltaRotation);
}

void Arota::TimeEvent()
{
	if (StaticMeshComp)
	{
		UMaterialInstanceDynamic* DynamicMat = StaticMeshComp->CreateAndSetMaterialInstanceDynamic(0);

		FLinearColor Color = FLinearColor(
			FMath::FRand(),
			FMath::FRand(),
			FMath::FRand(),
			1.0f
		);
		DynamicMat->SetVectorParameterValue(TEXT("Base Color"), Color);
	}
}