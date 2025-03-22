// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallDownBoll.generated.h"

UCLASS()
class ZHIYUEQIANJI_API AFallDownBoll : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFallDownBoll();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector FallDownPoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BollFallDown = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BollCanFallDown = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FallDownSpeed = 0.1;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void FallDown();
};
