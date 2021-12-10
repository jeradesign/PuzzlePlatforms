// Copyright 2021 Jera Design LLC


#include "MenuWidget.h"

#include "PuzzlePlatforms/MyCheckNull.h"

void UMenuWidget::ShowMenu()
{
	AddToViewport();

	const auto World = GetWorld();
	MYCHECKNULL(World);
	APlayerController* Controller = World->GetFirstPlayerController();
	MYCHECKNULL(Controller);
	FInputModeUIOnly UIOnly;
	UIOnly.SetWidgetToFocus(TakeWidget());
	UIOnly.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	Controller->SetInputMode(UIOnly);
	Controller->SetShowMouseCursor(true);
}

