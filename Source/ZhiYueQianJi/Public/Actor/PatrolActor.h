// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolActor.generated.h"

UCLASS()
class ZHIYUEQIANJI_API APatrolActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrolActor();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FVector> PatrolPoint;
	int PointNumbler = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PatrolMove = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 0.01;
	bool CanMove = true;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Move();
};
