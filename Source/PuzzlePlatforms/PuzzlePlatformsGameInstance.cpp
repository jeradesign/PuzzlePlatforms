// Copyright 2021 Jera Design LLC


#include "PuzzlePlatformsGameInstance.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
	static ConstructorHelpers::FClassFinder<UUserWidget> TheMenuClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (TheMenuClass.Class != NULL)
	{
		MenuClass = TheMenuClass.Class;
	}
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
	UE_LOG(LogTemp, Warning, TEXT("Class name: %s"), *(MenuClass->GetName()));
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

	UWorld* World = GetWorld();
	if (World == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("GetEngine() returned nullptr!"));
		return;
	}

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
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

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (PlayerController == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("GetFirstLocalPlayerController() returned nullptr!"));
		return;
	}
	PlayerController->ClientTravel(*IpAddr, TRAVEL_Absolute);
}
