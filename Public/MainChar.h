// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "PController_MainChar_Interface.h"
#include "MainChar.generated.h"

class UCameraComponent;

UCLASS()
class CRANCHY_MOVEMENTSYS_API AMainChar : public ACharacter, public IPController_MainChar_Interface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// Player Controller <-> Player Character Interface (C++ only)
	virtual void PlayerSprintFunction() override;
	virtual void PlayerCrouchFunction() override;


/////////////////////////////////////////////
//            ROOT COMPONENTS              // 
////////////////////////////////////////////

protected:
	// Adds a Camera Component to the char
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* PlayerThirdPersonView;

	// Adds a Spring Arm
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmThirdPersonView;

/////////////////////////////////////////////
//            VARIABLES                    // 
////////////////////////////////////////////

protected:
	// Default Max Walk Speed saved for later usage
	UPROPERTY()
	float DefaultMaxWalkSpeed;
};
