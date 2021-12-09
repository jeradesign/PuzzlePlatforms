// Copyright 2021 Jera Design LLC


#include "MainMenu.h"
#include "Components/Button.h"
#include "PuzzlePlatforms/MyCheckNull.h"

bool UMainMenu::Initialize()
{
	bool result = Super::Initialize();
	if (!result) { return false; }

	if (Host == nullptr) { return false; }

	Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	return true;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server!"));
	MYCHECKNULL(MenuInterface);
	MenuInterface->Host();
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
