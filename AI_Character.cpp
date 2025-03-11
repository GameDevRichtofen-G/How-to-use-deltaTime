// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Character.h"
#include <Kismet/KismetMathLibrary.h>


void AAI_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Calculate_rotation_speed(DeltaTime);


}


void AAI_Character::Calculate_rotation_speed(float deltaTime)
{
	FRotator Look_at_rotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Target_location));
	SetActorRotation(UKismetMathLibrary::RInterpTo(GetActorRotation(), FRotator(GetActorRotation().Pitch, Look_at_rotation.Yaw, Look_at_rotation.Roll), deltaTime, 1));
	float DeltaYaw = FMath::Abs(GetActorRotation().Yaw - Previous_rotation.Yaw);
	rotation_speed = DeltaYaw / (GetWorld()->GetDeltaSeconds() * (1 / 60));
	Previous_rotation = GetActorRotation();

}





