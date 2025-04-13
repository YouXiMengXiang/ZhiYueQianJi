// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/BaseMoveBlock.h"

ABaseMoveBlock::ABaseMoveBlock()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseMoveBlock::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorLocation(StartPoint);
	if(UesWaitTimeChangeCanMove)
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABaseMoveBlock::ChangeCanMove, WaitTime, false);

}

void ABaseMoveBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CanMove) {
		BlockMove();
	}
}


void ABaseMoveBlock::BlockMove()
{
	FVector BlockPoint = this->GetActorLocation();
	FVector MoveLocation = (TagerPoint - BlockPoint) * BlockMoveSpeed;
	FVector NewLocation = BlockPoint + MoveLocation;
	this->SetActorLocation(NewLocation);
	if (BlockPoint.Distance(BlockPoint, NewLocation) < 0.01) {
		CanMove = false;
	}
}

void ABaseMoveBlock::ChangeCanMove()
{
	CanMove = !CanMove;
}
