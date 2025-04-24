// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Seismograph.generated.h"

UCLASS()
class ZHIYUEQIANJI_API ASeismograph : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASeismograph();
	FTimerHandle TimerHandle; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FallDownTime = 4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> DownBoll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> DownOder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int cont = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void BollFallDown();
};
