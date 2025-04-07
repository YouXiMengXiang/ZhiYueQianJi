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

	//移动锁定
	bool MoveLock = false;

	//能否移动判断
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanMove = false;

	//下一个可以移动的鲁班锁成员
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ALuBanLock*> LastLockArray;
	bool ChangeLastFalg = true;
	//判断是否被解锁
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OpenLock = false;



	//移动方向设置
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

	//鲁班锁编号
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoveNuber = 0;

	//移动距离
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveDistance =4000;

	//移动速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 0.02;

	//移动目标点
	FVector TagerPoint;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void SetMoveDistance();

	UFUNCTION(BlueprintCallable, Category = "MyUseMove")
	void MoveTheLock();
	void UseMove();
	void ChangeLastLock();
};
