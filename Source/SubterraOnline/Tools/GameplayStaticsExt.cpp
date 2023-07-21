// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayStaticsExt.h"

#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

APlayerState* UGameplayStaticsExt::GetPlayerStateFromController(AController* Controller)
{
	return Controller->GetPlayerState<APlayerState>();
}

APlayerState* UGameplayStaticsExt::GetPlayerControllerState(const UObject* WorldContextObject, int32 PlayerIndex)
{
	if (auto* Controller = UGameplayStatics::GetPlayerController(WorldContextObject, PlayerIndex))
	{
		return GetPlayerStateFromController(Controller);
	}
	return nullptr;
}

