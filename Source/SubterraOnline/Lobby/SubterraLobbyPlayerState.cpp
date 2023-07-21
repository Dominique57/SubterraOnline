// Fill out your copyright notice in the Description page of Project Settings.


#include "SubterraLobbyPlayerState.h"
void ASubterraLobbyPlayerState::ChangePlayerName_Implementation(const FString& NewName) {
	// TODO: doesnt work if called from client
	if (HasNetOwner()) {
		SetPlayerName(NewName);
	} else {
		UE_LOG(LogTemp, Error, TEXT("Called change player from non-net-owned object !"));
	}
}
