// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SubterraLobbyPlayerState.generated.h"

/**
 *
 */
UCLASS()
class SUBTERRAONLINE_API ASubterraLobbyPlayerState : public APlayerState {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void ChangePlayerName(const FString& NewName);
};
