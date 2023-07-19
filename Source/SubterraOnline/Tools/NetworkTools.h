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
	static IOnlineSubsystem* GetSessionInterface();
	static IOnlineSessionPtr GetSessionManager();
	static FNamedOnlineSession* GetDefaultSession();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network")
	static FName GetDefaultSessionName();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network")
	static bool IsSessionValid(FName SessionName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network")
	static FString GetSessionConnectionString(FName SessionName);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network")
	static int GetSessionsNum();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Mine|Tools|Network")
	static FString GetNetMode(AActor* Test);
};
