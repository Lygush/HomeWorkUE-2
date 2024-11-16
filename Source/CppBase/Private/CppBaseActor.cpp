// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ACppBaseActor::ACppBaseActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector ACppBaseActor::SinMovement()
{
	float z = (FMath::Sin((UGameplayStatics::GetRealTimeSeconds(this) * Frequency))) * Amplitude;
	InitialLocation.Z += z;
	return InitialLocation;
}
