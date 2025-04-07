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

	//�ƶ�����
	bool MoveLock = false;

	//�ܷ��ƶ��ж�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanMove = false;

	//��һ�������ƶ���³������Ա
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ALuBanLock*> LastLockArray;
	bool ChangeLastFalg = true;
	//�ж��Ƿ񱻽���
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OpenLock = false;



	//�ƶ���������
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

	//³�������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoveNuber = 0;

	//�ƶ�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveDistance =4000;

	//�ƶ��ٶ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 0.02;

	//�ƶ�Ŀ���
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
