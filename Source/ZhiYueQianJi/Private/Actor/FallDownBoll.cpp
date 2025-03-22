// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/FallDownBoll.h"

// Sets default values
AFallDownBoll::AFallDownBoll()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFallDownBoll::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFallDownBoll::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (BollCanFallDown) {
		FallDown();
	}
}

void AFallDownBoll::FallDown()
{
	FVector BlockPoint = this->GetActorLocation();
	FVector MoveLocation = (FallDownPoint - BlockPoint) * FallDownSpeed;
	FVector NewLocation = BlockPoint + MoveLocation;
	this->SetActorLocation(NewLocation);
	if (FVector::Distance(BlockPoint, NewLocation) < 0.1) {
		BollFallDown = true;
		BollCanFallDown = false;
	}

}

