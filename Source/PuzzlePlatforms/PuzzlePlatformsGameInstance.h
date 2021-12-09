// Copyright 2021 Jera Design LLC

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	explicit UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(Exec)
	virtual void BeginHosting() override;

	UFUNCTION(Exec)
	virtual void JoinServer(const FString& IpAddr) override;

	UFUNCTION(Exec, BlueprintCallable, Category="My Menu")
	void LoadMenu();

private:
	TSubclassOf<UUserWidget> MenuClass;
};
