// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayStaticsExt.generated.h"

/**
 * 
 */
UCLASS()
class SUBTERRAONLINE_API UGameplayStaticsExt : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Game")
	static APlayerState* GetPlayerStateFromController(AController* Controller);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Game", meta=(WorldContext="WorldContextObject", UnsafeDuringActorConstruction="true"))
	static APlayerState* GetPlayerControllerState(const UObject* WorldContextObject, int32 PlayerIndex);
};
