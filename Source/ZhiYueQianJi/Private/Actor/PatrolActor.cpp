// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PatrolActor.h"

// Sets default values
APatrolActor::APatrolActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APatrolActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatrolActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void APatrolActor::Move()
{
	if (CanMove&&PatrolPoint.Num()) {

		FVector BlockPoint = this->GetActorLocation();
		FVector MoveLocation = (PatrolPoint[PointNumbler] - BlockPoint) * MoveSpeed;
		FVector NewLocation = BlockPoint + MoveLocation;
		this->SetActorLocation(NewLocation);
		if (BlockPoint.Distance(BlockPoint, NewLocation) < 0.01) {
			if (PointNumbler + 1 < PatrolPoint.Num()) {
				PointNumbler++;
			}
			else if(PatrolMove) {
				PointNumbler = 0;
			}
			else {
				CanMove = false;
			}
		}
	}
}

