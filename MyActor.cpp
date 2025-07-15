﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	SetRootComponent(StaticMeshComp);

	MoveSpeed = 1.f;
	MaxRange = 150.f;
	Direction = 1;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector DeltaLocation = GetActorLocation() * DeltaTime * MoveSpeed * Direction;
	AddActorLocalOffset(DeltaLocation);

	FVector V3 = StartLocation - GetActorLocation();
	float Distance = V3.Length();

	if (Distance >= MaxRange)
	{
		StartLocation = GetActorLocation();
		Direction *= -1;
	}
}

