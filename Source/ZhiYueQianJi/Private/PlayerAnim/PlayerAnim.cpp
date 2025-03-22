#include "PlayerAnim/PlayerAnim.h"
#include "Character/MainPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
void UPlayerAnim::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	MainPlayer = Cast<AMainPlayer>(TryGetPawnOwner());
	if (MainPlayer)
	{
		PlayerCharacterMovement = MainPlayer->GetCharacterMovement();
	}
}

void UPlayerAnim::NativeUpdateAnimation(float DelataTime)
{
	Super::NativeInitializeAnimation();
	if (PlayerCharacterMovement)
	{
		speed = UKismetMathLibrary::VSizeXY(PlayerCharacterMovement->Velocity);
	}
}
