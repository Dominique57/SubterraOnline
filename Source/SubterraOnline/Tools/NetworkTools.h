// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "NetworkTools.generated.h"

/**
 *
 */
UCLASS()
class SUBTERRAONLINE_API UNetworkTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static IOnlineSubsystem* GetSessionInterface(UObject* World);
	static IOnlineSessionPtr GetSessionManager(UObject* World);
	static FNamedOnlineSession* GetDefaultSession(UObject* World);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network")
	static FName GetDefaultSessionName();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network", meta=(WorldContext=WorldContext))
	static bool IsSessionValid(UObject* WorldContext, FName SessionName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network", meta=(WorldContext=WorldContext))
	static FString GetSessionConnectionString(UObject* WorldContext, FName SessionName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network", meta=(WorldContext=WorldContext))
	static int GetSessionsNum(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network")
	static FString GetNetMode(AActor* Test);
};
