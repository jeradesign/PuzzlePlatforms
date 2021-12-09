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
	class UButton *Host;

	UPROPERTY(meta = (BindWidget))
	class UButton *Join;

	UFUNCTION()
	void HostServer();

	IMenuInterface* MenuInterface;
};
