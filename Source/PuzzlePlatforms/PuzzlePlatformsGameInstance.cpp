// Copyright 2021 Jera Design LLC


#include "PuzzlePlatformsGameInstance.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPuzzlePlatformsGameInstance::Host()
{
	auto Engine(GetEngine());
	if (Engine == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("GetEngine() returned nullptr!"));
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 10.0f, FColor::Green, "Hosting");
}

void UPuzzlePlatformsGameInstance::Join(const FString& IpAddr)
{
	auto Engine(GetEngine());
	if (Engine == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("GetEngine() returned nullptr!"));
		return;
	}

	FString Message = "Joining: " + IpAddr;

	Engine->AddOnScreenDebugMessage(0, 10.0f, FColor::Green, Message);
}

