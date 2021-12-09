// Copyright 2021 Jera Design LLC

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);
	void ShowMenu(IMenuInterface* Target, APlayerController* LocalController);

protected:
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton *EnterHostModeButton;

	UPROPERTY(meta = (BindWidget))
	class UButton *ShowJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressTextBox;

	UPROPERTY(meta = (BindWidget))
	class UButton *JoinGameButton;

	UPROPERTY(meta = (BindWidget))
	class UButton *BackButton;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void ShowJoinMenu();

	UFUNCTION()
	void JoinRemoteServer();

	UFUNCTION()
	void GoBack();

	IMenuInterface* MenuInterface;
};
