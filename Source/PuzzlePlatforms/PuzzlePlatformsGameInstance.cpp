// Copyright 2021 Jera Design LLC


#include "PuzzlePlatformsGameInstance.h"

#include "MyCheckNull.h"

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
	MYCHECKNULL(Engine);

	Engine->AddOnScreenDebugMessage(0, 10.0f, FColor::Green, "Hosting");

	UWorld* World = GetWorld();
	MYCHECKNULL(World);

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString& IpAddr)
{
	auto Engine(GetEngine());
	MYCHECKNULL(Engine);
	FString Message = "Joining: " + IpAddr;

	Engine->AddOnScreenDebugMessage(0, 10.0f, FColor::Green, Message);

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	MYCHECKNULL(PlayerController);
	PlayerController->ClientTravel(*IpAddr, TRAVEL_Absolute);
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{
	MYCHECKNULL(MenuClass);
	UUserWidget* MenuWidget(CreateWidget<UUserWidget>(this, MenuClass));
	MYCHECKNULL(MenuWidget);

	MenuWidget->AddToViewport();
}
