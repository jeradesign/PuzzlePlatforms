// Copyright 2021 Jera Design LLC


#include "PuzzlePlatformsGameInstance.h"

#include "InGameMenu.h"
#include "MyCheckNull.h"
#include "MenuSystem/MainMenu.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
	static ConstructorHelpers::FClassFinder<UUserWidget> TheMenuClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	MYCHECKNULL(TheMenuClass.Class);
	MenuClass = TheMenuClass.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> TheInGameMenu(TEXT("/Game/UI/WBP_InGameMenu"));
	MYCHECKNULL(TheInGameMenu.Class);
	InGameMenuClass = TheInGameMenu.Class;
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
	UE_LOG(LogTemp, Warning, TEXT("Class name: %s"), *(MenuClass->GetName()));
}

void UPuzzlePlatformsGameInstance::BeginHosting()
{
	const auto Engine(GetEngine());
	MYCHECKNULL(Engine);

	Engine->AddOnScreenDebugMessage(0, 10.0f, FColor::Green, "Hosting");

	UWorld* World = GetWorld();
	MYCHECKNULL(World);
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::JoinServer(const FString& IpAddr)
{
	const auto Engine(GetEngine());
	MYCHECKNULL(Engine);
	const FString Message = "Joining: " + IpAddr;

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
	const auto LocalController = GetFirstLocalPlayerController();
	MYCHECKNULL(LocalController);

	MenuWidget->SetMenuInterface(this);
	MenuWidget->ShowMenu();
}

void UPuzzlePlatformsGameInstance::LoadInGameMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("LoadInGameMenu"));
	MYCHECKNULL(InGameMenuClass);
	UMenuWidget* InGameMenuWidget(CreateWidget<UMenuWidget>(this, InGameMenuClass));
	MYCHECKNULL(InGameMenuWidget);
	const auto LocalController = GetFirstLocalPlayerController();
	MYCHECKNULL(LocalController);

	InGameMenuWidget->ShowMenu();
}
