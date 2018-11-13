// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerControlledTank = GetPlayerTank();
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		
		AimAtPlayerLocation();
	}

}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto  PlayerControlledTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerControlledTank) { return nullptr; }

	return Cast<ATank>(PlayerControlledTank);
}

void ATankAIController::AimAtPlayerLocation()
{
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

