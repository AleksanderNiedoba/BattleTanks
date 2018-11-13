// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	void SetBarrelReference(UStaticMeshComponent * BarrelToSet);
	
	UTankAimingComponent();

	void AimAtLocation(FVector, float);

private:
	UStaticMeshComponent * Barrel = nullptr;
	void MoveBarrel(FVector);
};
