#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI_Character.generated.h"

UCLASS()
class RADAR_API AAI_Character : public ACharacter
{
	GENERATED_BODY()

public:

	AAI_Character();

protected:

	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "variables")
		float rotation_speed;

private :
	FRotator Previous_rotation;
};












