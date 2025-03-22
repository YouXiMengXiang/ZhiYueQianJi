#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnim.generated.h"


class AMainPlayer;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class ZHIYUEQIANJI_API UPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()
public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DelataTime) override;

	UPROPERTY(BLueprintReadOnly)
	TObjectPtr<AMainPlayer> MainPlayer;

	UPROPERTY(BLueprintReadOnly)
	TObjectPtr<UCharacterMovementComponent> PlayerCharacterMovement;

	UPROPERTY(BLueprintReadOnly)
	float speed;
};
