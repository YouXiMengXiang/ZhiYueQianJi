// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseMoveBlock.generated.h"

UCLASS()
class ZHIYUEQIANJI_API ABaseMoveBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseMoveBlock();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TagerPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BlockMoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanMove = false;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void BlockMove();
};
