// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto FirstPlayerTank = GetPlayerTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController has not posessed a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled tank is %s"), *ControlledTank->GetName());

		if (!FirstPlayerTank) {
			UE_LOG(LogTemp, Warning, TEXT("Could not find First Player Tank"));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("AI tank %s found First Player tank %s"), *ControlledTank->GetName(), *FirstPlayerTank->GetName());
		}
	}
}

ATank * ATankAIController::GetPlayerTank() const {
	ATank* PlayerTank = nullptr;

	auto CurrentLevel = GetWorld();
	if (CurrentLevel) {
		auto FirstPlayerController = CurrentLevel->GetFirstPlayerController();
		if (FirstPlayerController) {
			auto PlayerPawn = FirstPlayerController->GetPawn();
			if (PlayerPawn) {
				PlayerTank = Cast<ATank>(PlayerPawn);
			} else {
				UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a Pawn"))
			}
		} else {
			UE_LOG(LogTemp, Warning, TEXT("Player Controller not found"))
		}
	} else {
		UE_LOG(LogTemp, Warning, TEXT("World not loaded"))
	}
		
	return PlayerTank;
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}