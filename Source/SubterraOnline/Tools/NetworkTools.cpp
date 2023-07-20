// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkTools.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystem.h"

IOnlineSubsystem* UNetworkTools::GetSessionInterface(UObject* World)
{
	auto* OnlineSubsystem = Online::GetSubsystem(GEngine->GetWorldFromContextObject(World, EGetWorldErrorMode::ReturnNull));
	check(OnlineSubsystem);
	return OnlineSubsystem;
}

IOnlineSessionPtr UNetworkTools::GetSessionManager(UObject* World)
{
	const auto SessionManager = GetSessionInterface(World)->GetSessionInterface();
	check(SessionManager.Get());
	return SessionManager;
}

FNamedOnlineSession* UNetworkTools::GetDefaultSession(UObject* World)
{
	auto* Session = GetSessionManager(World)->GetNamedSession(EName::GameSession);
	return Session;
}

FName UNetworkTools::GetDefaultSessionName()
{
	return EName::GameSession;
}

bool UNetworkTools::IsSessionValid(UObject* WorldContext, FName SessionName)
{
	const auto* Session = GetSessionManager(WorldContext)->GetNamedSession(SessionName);
	return Session != nullptr;
}

FString UNetworkTools::GetSessionConnectionString(UObject* WorldContext, FName SessionName)
{
	const auto SessionManager = GetSessionManager(WorldContext);
	FString ConnectInfo;
	if (SessionManager->GetResolvedConnectString(SessionName, ConnectInfo))
		return ConnectInfo;
	return FString();
}

int UNetworkTools::GetSessionsNum(UObject* WorldContext)
{
	const auto SessionManager = GetSessionManager(WorldContext);
	return SessionManager->GetNumSessions();
}

static inline FString toString(ENetRole Mode) {
	switch (Mode) {
	case ENetRole::ROLE_Authority:
		return TEXT("Authority");
	case ENetRole::ROLE_AutonomousProxy:
		return TEXT("AutonomousProxy");
	case ENetRole::ROLE_SimulatedProxy:
		return TEXT("SimulatedProxy");
	case ENetRole::ROLE_None:
		return TEXT("None");
	default: ;
	}
	return TEXT("");
}

static inline FString toString(ENetMode Mode) {
	switch (Mode) {
	case ENetMode::NM_Client:
		return TEXT("NM_Client");
	case ENetMode::NM_Standalone:
		return TEXT("NM_Standalone");
	case ENetMode::NM_DedicatedServer:
		return TEXT("NM_DedicatedServer");
	case ENetMode::NM_ListenServer:
		return TEXT("NM_ListenServer");
	default: ;
	}
	return TEXT("");
}

FString UNetworkTools::GetNetMode(AActor* Test)
{
	return FString("NetMode: ") + toString(Test->GetNetMode())
		+ " Local: " + toString(Test->GetLocalRole())
		+ " Remote : " + toString(Test->GetRemoteRole());
}
