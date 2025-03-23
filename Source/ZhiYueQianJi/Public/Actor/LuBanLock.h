// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LuBanLock.generated.h"

UCLASS()
class ZHIYUEQIANJI_API ALuBanLock : public AActor
{
	GENERATED_BODY()
	
public:	
	ALuBanLock();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool MoveLock = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RedRightMove = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RedLeftMove = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UpMove = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool GreenRightMove = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool GreenLeftMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoveNuber = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveDistance =4000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 0.02;
	FVector TagerPoint;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void SetMoveDistance();

	UFUNCTION(BlueprintCallable, Category = "MyUseMove")
	void UseMove();
};
