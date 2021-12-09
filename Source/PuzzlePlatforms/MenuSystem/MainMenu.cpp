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
