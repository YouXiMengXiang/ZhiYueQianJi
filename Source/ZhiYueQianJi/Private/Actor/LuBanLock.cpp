// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/LuBanLock.h"

// Sets default values
ALuBanLock::ALuBanLock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALuBanLock::BeginPlay()
{
	Super::BeginPlay();
	SetMoveDistance();
}

// Called every frame
void ALuBanLock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (MoveLock)
		UseMove();
}

void ALuBanLock::SetMoveDistance()
{
	if (RedRightMove) {
		TagerPoint = this->GetActorLocation() + FVector(MoveDistance, 0, 0);
	}
	else if (RedLeftMove) {
		TagerPoint = this->GetActorLocation() + FVector(-MoveDistance, 0, 0);
	}
	else if (UpMove) {
		TagerPoint = this->GetActorLocation() + FVector(0, 0, MoveDistance);
	}else if (GreenRightMove) {
		TagerPoint = this->GetActorLocation() + FVector(0,MoveDistance , 0);
	}
	else if (GreenLeftMove) {
		TagerPoint = this->GetActorLocation() + FVector(0,-MoveDistance , 0);
	}
}


void ALuBanLock::UseMove()
{
	FVector BlockPoint = this->GetActorLocation();
	FVector MoveLocation = (TagerPoint - BlockPoint) * MoveSpeed;
	FVector NewLocation = BlockPoint + MoveLocation;
	this->SetActorLocation(NewLocation);
	if (BlockPoint.Distance(BlockPoint, NewLocation) < 1) {
		//this->Destroy();
		MoveLock = false;
		
	}
	
}

