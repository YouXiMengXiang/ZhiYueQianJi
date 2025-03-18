

#include "Actor/FallDownBlock.h"

AFallDownBlock::AFallDownBlock()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFallDownBlock::BeginPlay()
{
	Super::BeginPlay();
	TagerPoint = this->GetActorLocation() + FVector(0, 0, FallDownDistance);
}

void AFallDownBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CanFallDown) {
		BlockFallDown();
	}
}

void AFallDownBlock::BlockFallDown()
{
	FVector BlockPoint = this->GetActorLocation();
	FVector MoveLocation = (TagerPoint - BlockPoint) * BlockMoveSpeed;
	FVector NewLocation = BlockPoint + MoveLocation;
	this->SetActorLocation(NewLocation);
	if (BlockPoint.Distance(BlockPoint, NewLocation) < 1) {
		this->Destroy();
	}
}

