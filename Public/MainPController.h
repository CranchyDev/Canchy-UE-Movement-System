// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "PController_MainChar_Interface.h"
#include "MainPController.generated.h"

/**
 * 
 */
UCLASS()
class CRANCHY_MOVEMENTSYS_API AMainPController : public APlayerController, public IPController_MainChar_Interface
{
	GENERATED_BODY()

public:

	// Called to bind functionality to input

	virtual void SetupInputComponent() override;

	// Called to bind Begin Play to this class

	virtual void BeginPlay() override;

public:
	// Player Controller <-> Player Character Interface (C++ only)
	virtual void PlayerSprintFunction() override;
	virtual void PlayerCrouchFunction() override;


/////////////////////////////////////////////
// PLAYER INPUT FUNCTIONALITY BEGINS HERE // 
////////////////////////////////////////////

protected:

// >>>>>>>>>>>> Input Mapping Context <<<<<<<<<<<<<<<

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputMappingContext> Movement_InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> OnlyUI_InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement")
	TObjectPtr<UInputAction> CameraRotationInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input|Movement")
	TObjectPtr<UInputAction> Movement_AnyInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement")
	TObjectPtr<UInputAction> Jump_AnyInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement")
	TObjectPtr<UInputAction> Sprint_AnyInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement")
	TObjectPtr<UInputAction> Crouch_AnyInput;

// >>>>>>>>>>>> MOVEMENT ACTIONS FOR KEYBOARD <<<<<<<<<<<<<<<
// >>>>> FUNCTIONS <<<<<

public:

	UFUNCTION()
	void CameraRotation(const FInputActionValue& Value);

	UFUNCTION()
	void MoveWASDF(const FInputActionValue& MovementScaleFactor);

	UFUNCTION()
	void PlayerJump_Start();

	UFUNCTION()
	void PlayerJump_End();

	UFUNCTION()
	void PlayerSprint();

	UFUNCTION()
	void PlayerCrouch();

/////////////////////////////////////////////
// PLAYER INPUT FUNCTIONALITY ENDS HERE // 
////////////////////////////////////////////
};
