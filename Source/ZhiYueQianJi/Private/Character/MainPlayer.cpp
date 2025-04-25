#include "Character/MainPlayer.h"


AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->SetRelativeRotation(FRotator( - 70.f, 0.f, 0.f));

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	PlayerCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);

	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;

	CameraBoom->bUsePawnControlRotation = true;
	PlayerCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 800.f, 0.f);

}

void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	if (const ULocalPlayer* Player = (GEngine && GetWorld()) ? GEngine->GetFirstGamePlayer(GetWorld()) : nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Player);
		if (DefaultMapping) {
			Subsystem->AddMappingContext(DefaultMapping, 0);
		}
	}
}

void AMainPlayer::Move(const FInputActionValue& Value)
{
	FVector2D MoveVector = Value.Get<FVector2D>();
	if (Controller) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotator(0, Rotation.Yaw, 0);
		const FVector ForwardDirection = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
		AddMovementInput(ForwardDirection, MoveVector.X);
		AddMovementInput(RightDirection, MoveVector.Y);
	}

}
void AMainPlayer::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();
	if (Controller)
	{
		AddControllerYawInput(-LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}

}

void AMainPlayer::AnimMontagePlay(UAnimMontage* MontageToPlay, FName SectionName, float PlayRate)
{
	UAnimInstance* AnimInstance = Cast<UAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInstance && MontageToPlay)
	{
		//检查动画蒙太奇是否在播放
		if (!AnimInstance->Montage_IsPlaying(MontageToPlay))
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, FString::Printf(TEXT("Jump test")));
			PlayAnimMontage(MontageToPlay, PlayRate, SectionName);
		}
	}

}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked< UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainPlayer::Look);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainPlayer::Move);
		EnhancedInputComponent->BindAction(MouseUseAction, ETriggerEvent::Triggered, this, &AMainPlayer::HandleLeftMouseClick);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainPlayer::PlayerJump);
	}

}

void AMainPlayer::ShowMouse()
{
	// 获取玩家控制器
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		// 启用鼠标光标和点击事件
		PlayerController->bShowMouseCursor = true;
		PlayerController->bEnableClickEvents = true;
		PlayerController->bEnableMouseOverEvents = true;
	}

}

void AMainPlayer::CloseMouse()
{
	// 获取玩家控制器
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		// 启用鼠标光标和点击事件
		PlayerController->bShowMouseCursor = false;
		PlayerController->bEnableClickEvents = false;
		PlayerController->bEnableMouseOverEvents = false;
	}
}

void AMainPlayer::UpFly()
{
	GetCharacterMovement()->AddImpulse(FVector(0, 0, UpFlyForce), true);
}

void AMainPlayer::HandleLeftMouseClick()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		FVector WorldLocation, WorldDirection;
		if (PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
		{
			FHitResult HitResult;
			FCollisionQueryParams CollisionParams;
			CollisionParams.bTraceComplex = true;
			if (GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, WorldLocation + WorldDirection * 10000, ECC_Visibility, CollisionParams))
			{
				AActor* HitActor = HitResult.GetActor();
				if (HitActor)
				{
					//此处操作被点击的物体
					ALuBanLock* LuBanLock = Cast<ALuBanLock>(HitActor);
					if (LuBanLock) {
						LuBanLock->MoveTheLock();
					}
					//UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *HitActor->GetName());
				}
			}
		}
	}

}

void AMainPlayer::PlayerJump()
{
	if (GetCharacterMovement()->IsMovingOnGround()) {
		AnimMontagePlay(JumpMontage, FName("Jump"));
		//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, FString::Printf(TEXT("Jump test")));

		GetCharacterMovement()->AddImpulse(FVector(0, 0, JumpForce), true);
	}
}