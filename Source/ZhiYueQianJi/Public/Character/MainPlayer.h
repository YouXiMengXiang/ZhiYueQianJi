#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

#include "Actor/LuBanLock.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "MainPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class ZHIYUEQIANJI_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMainPlayer();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float JumpForce = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float UpFlyForce = 10000;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext>DefaultMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MouseUseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> PlayerCamera;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)	
	void ShowMouse();
	UFUNCTION(BlueprintCallable)
	void UpFly();
	void HandleLeftMouseClick();
	void PlayerJump();

};
