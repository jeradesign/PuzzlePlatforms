// Copyright 2021 Jera Design LLC


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "PuzzlePlatforms/MyCheckNull.h"

bool UMainMenu::Initialize()
{
	bool result = Super::Initialize();
	if (!result) { return false; }

	MYCHECKNULL2(EnterHostModeButton, return false);
	EnterHostModeButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	MYCHECKNULL2(ShowJoinMenuButton, return false);
	ShowJoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::ShowJoinMenu);
	// if (JoinGameButton == nullptr) { return false; }
	// JoinGameButton->OnClicked.AddDynamic(this, &UMainMenu::JoinRemoteServer);
	MYCHECKNULL2(BackButton, return false);
	BackButton->OnClicked.AddDynamic(this, &UMainMenu::GoBack);

	return true;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server!"));
	MYCHECKNULL(MenuInterface);
	MenuInterface->BeginHosting();
}

void UMainMenu::ShowJoinMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Showing join menu"));
	MYCHECKNULL(MenuSwitcher);
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::JoinRemoteServer()
{
}

void UMainMenu::GoBack()
{
	MYCHECKNULL(MenuSwitcher);
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::SetMenuInterface(IMenuInterface* TheMenuInterface)
{
	this->MenuInterface = TheMenuInterface;
}

void UMainMenu::ShowMenu(IMenuInterface* Target, APlayerController* LocalController)
{
	MYCHECKNULL(Target);
	SetMenuInterface(Target);
	AddToViewport();

	MYCHECKNULL(LocalController);
	FInputModeUIOnly UIOnly;
	UIOnly.SetWidgetToFocus(TakeWidget());
	UIOnly.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	LocalController->SetInputMode(UIOnly);
	LocalController->SetShowMouseCursor(true);
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
	FInputModeGameOnly GameOnly;
	const auto PlayerController = InWorld->GetFirstPlayerController();
	PlayerController->SetInputMode(GameOnly);
	PlayerController->SetShowMouseCursor(false);
	RemoveFromParent();
}
