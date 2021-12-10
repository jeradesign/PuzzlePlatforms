// Copyright 2021 Jera Design LLC


#include "InGameMenu.h"

#include "MyCheckNull.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	const bool bResult = Super::Initialize();
	if (!bResult) { return false; }

	MYCHECKNULL2(LobbyButton, return false);
	LobbyButton->OnClicked.AddDynamic(this, &UInGameMenu::GoToLobby);
	MYCHECKNULL2(BackButton, return false);
	BackButton->OnClicked.AddDynamic(this, &UInGameMenu::ExitMenu);

	return true;
}

void UInGameMenu::GoToLobby()
{
	UE_LOG(LogTemp, Warning, TEXT("GoToLobby"));
}

void UInGameMenu::ExitMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("ExitMenu"));
}
