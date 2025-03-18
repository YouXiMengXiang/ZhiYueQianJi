
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallDownBlock.generated.h"

UCLASS()
class ZHIYUEQIANJI_API AFallDownBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	AFallDownBlock();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TagerPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BlockMoveSpeed = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FallDownDistance = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanFallDown = false;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void BlockFallDown();
};
