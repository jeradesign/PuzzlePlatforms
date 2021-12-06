// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		auto Location = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(Location);
		Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}


void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!HasAuthority())
	{
		return;
	}

	auto Location = GetActorLocation();

	Location += Speed * DeltaTime * Direction;

	SetActorLocation(Location);
}
