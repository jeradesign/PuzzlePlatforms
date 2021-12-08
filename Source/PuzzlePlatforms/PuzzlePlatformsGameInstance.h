// Copyright 2021 Jera Design LLC

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& IpAddr);

	UFUNCTION(Exec, BlueprintCallable, Category="My Menu")
	void LoadMenu();

private:
	TSubclassOf<UUserWidget> MenuClass;
};
