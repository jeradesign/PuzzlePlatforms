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

	if (!HasAuthority())
	{
		return;
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	DistanceToEnd = FVector::Distance(GlobalStartLocation, GlobalTargetLocation);
	Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
	StartDirection = Direction;
	SetReplicates(true);
	SetReplicateMovement(true);
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
	float Dist = FVector::Distance(Location, GlobalStartLocation);
	if (Dist > DistanceToEnd)
	{
		std::swap(GlobalTargetLocation, GlobalStartLocation);
		Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		SetActorLocation(GlobalStartLocation);
	}
	else
	{
		SetActorLocation(Location);
	}
}
