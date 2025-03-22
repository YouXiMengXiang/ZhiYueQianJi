// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Seismograph.h"
#include "Actor/FallDownBoll.h"
// Sets default values
ASeismograph::ASeismograph()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASeismograph::BeginPlay()
{
	Super::BeginPlay();
	BollFallDown();
}

// Called every frame
void ASeismograph::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASeismograph::BollFallDown()
{
	int32 RandomInt = FMath::RandRange(0, 7);
	AActor* FallDownActor = Cast<AActor>( DownBoll[RandomInt]);
	AFallDownBoll* Boll = Cast<AFallDownBoll>(FallDownActor);
	if (Boll) {
		Boll->BollCanFallDown = true;
	}

}

