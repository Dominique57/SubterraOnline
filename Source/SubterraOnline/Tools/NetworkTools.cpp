// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkTools.h"
#include "OnlineSubsystem.h"

IOnlineSubsystem* UNetworkTools::GetSessionInterface()
{
	auto* OnlineSubsystem = IOnlineSubsystem::Get();
	check(OnlineSubsystem);
	return OnlineSubsystem;
}

IOnlineSessionPtr UNetworkTools::GetSessionManager()
{
	const auto SessionManager = GetSessionInterface()->GetSessionInterface();
	check(SessionManager.Get());
	return SessionManager;
}

FNamedOnlineSession* UNetworkTools::GetDefaultSession()
{
	auto* Session = GetSessionManager()->GetNamedSession(EName::GameSession);
	return Session;
}

FName UNetworkTools::GetDefaultSessionName()
{
	return EName::GameSession;
}

bool UNetworkTools::IsSessionValid(FName SessionName)
{
	const auto* Session = GetSessionManager()->GetNamedSession(SessionName);
	return Session != nullptr;
}

FString UNetworkTools::GetSessionConnectionString(FName SessionName)
{
	const auto SessionManager = GetSessionManager();
	FString ConnectInfo;
	if (SessionManager->GetResolvedConnectString(SessionName, ConnectInfo))
		return ConnectInfo;
	return FString();
}

int UNetworkTools::GetSessionsNum()
{
	const auto SessionManager = GetSessionManager();
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
