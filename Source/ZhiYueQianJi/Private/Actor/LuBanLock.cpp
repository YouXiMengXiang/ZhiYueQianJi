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


void ALuBanLock::MoveTheLock()
{
	if (CanMove) {
		MoveLock = true;
		if (MoveNumber == 6)LastLevel = true;
	}else {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("Can`t move this block")));
	}
}

void ALuBanLock::UseMove()
{
	if (ChangeLastFalg) {
	ChangeLastLock();
	ChangeLastFalg = false;
	}
	FVector BlockPoint = this->GetActorLocation();
	FVector MoveLocation = (TagerPoint - BlockPoint) * MoveSpeed;
	FVector NewLocation = BlockPoint + MoveLocation;
	this->SetActorLocation(NewLocation);
	if (BlockPoint.Distance(BlockPoint, NewLocation) < 1) {
		//this->Destroy();
		MoveLock = false;
		OpenLock = true;
	}
	
}

void ALuBanLock::ChangeLastLock()
{
	for (int i = 0; i < LastLockArray.Num(); i++) {
		ALuBanLock* Last = Cast<ALuBanLock>(LastLockArray[i]);
		if (Last) {
			Last->CanMove = true;
		}
	}
}

