// Copyright 2021 Jera Design LLC


#include "PuzzlePlatformsGameInstance.h"

#include "MyCheckNull.h"
#include "MenuSystem/MainMenu.h"

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
	UMainMenu* MenuWidget(CreateWidget<UMainMenu>(this, MenuClass));
	MYCHECKNULL(MenuWidget);

	MenuWidget->AddToViewport();
	MenuWidget->SetMenuInterface(this);

	auto LocalController = GetFirstLocalPlayerController();
	MYCHECKNULL(LocalController);
	FInputModeUIOnly UIOnly;
	UIOnly.SetWidgetToFocus(MenuWidget->TakeWidget());
	UIOnly.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	LocalController->SetInputMode(UIOnly);
	LocalController->SetShowMouseCursor(true);
}
