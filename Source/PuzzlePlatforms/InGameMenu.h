// Copyright 2021 Jera Design LLC

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MenuWidget.h"
#include "InGameMenu.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()

public:

protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton *LobbyButton;

	UPROPERTY(meta = (BindWidget))
	class UButton *BackButton;

	UFUNCTION()
	void GoToLobby();

	UFUNCTION()
	void ExitMenu();
};
