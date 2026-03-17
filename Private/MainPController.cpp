// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPController.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

void AMainPController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		InputSubsystem->AddMappingContext(Movement_InputMapping, 0);
	}
}



void AMainPController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Binding Action To -> Camera Rotation around the Character
		EnhancedInput->BindAction(CameraRotationInput, ETriggerEvent::Triggered, this, &AMainPController::CameraRotation);

		// Binding Action to -> Movement Forward, Backward, Left and Right
		EnhancedInput->BindAction(Movement_AnyInput, ETriggerEvent::Triggered, this, &AMainPController::MoveWASDF);

		// Binding Action to -> Jump
		EnhancedInput->BindAction(Jump_AnyInput, ETriggerEvent::Started, this, &AMainPController::PlayerJump_Start);
		EnhancedInput->BindAction(Jump_AnyInput, ETriggerEvent::Completed, this, &AMainPController::PlayerJump_End);

		// Binding Action to -> Sprint
		EnhancedInput->BindAction(Sprint_AnyInput, ETriggerEvent::Started, this, &AMainPController::PlayerSprint);
		EnhancedInput->BindAction(Sprint_AnyInput, ETriggerEvent::Completed, this, &AMainPController::PlayerSprint);

		// Binding Action to -> Crouch
		EnhancedInput->BindAction(Crouch_AnyInput, ETriggerEvent::Started, this, &AMainPController::PlayerCrouch);
		EnhancedInput->BindAction(Crouch_AnyInput, ETriggerEvent::Completed, this, &AMainPController::PlayerCrouch);
	}
}

void AMainPController::CameraRotation(const FInputActionValue& Value)
{
	// Vector2D: X is Mouse X (Yaw), Y is Mouse Y (Pitch)
	const FVector2D LookAxisValue = Value.Get<FVector2D>();

	// Add Yaw (Left/Right)
	AddYawInput(LookAxisValue.X);

	// Add Pitch (Up/Down)
	AddPitchInput(LookAxisValue.Y);
}

void AMainPController::MoveWASDF(const FInputActionValue& MovementScaleFactor)
{
	if (APawn* ControlledChar = GetPawn())
	{
		if (!ControlledChar)
		{
			return;
		}
		else
		{
			// LookAxis will be used to determine which direction the Character should move in the world
			const FVector2D LookAxis = MovementScaleFactor.Get<FVector2D>();

			if (LookAxis.IsZero())
			{
				return;
			}
			else
			{
				// Movement Forward and Backward
				const FRotator LookYawRot(0.f, GetControlRotation().Yaw, 0.f);

				const FVector ForwardDirection = FRotationMatrix(LookYawRot).GetUnitAxis(EAxis::X);

				ControlledChar->AddMovementInput(ForwardDirection, LookAxis.X);

				// Movement Left and Right
				const FVector LeftRightDirection = FRotationMatrix(LookYawRot).GetUnitAxis(EAxis::Y);

				ControlledChar->AddMovementInput(LeftRightDirection, LookAxis.Y);
			}
		}
	}
}

void AMainPController::PlayerJump_Start()
{
	if (ACharacter* ControlledChar = Cast<ACharacter>(GetPawn()))
	{
		ControlledChar->Jump();
	}
}

void AMainPController::PlayerJump_End()
{
	if (ACharacter* ControlledChar = Cast<ACharacter>(GetPawn()))
	{
		ControlledChar->StopJumping();
	}
}

void AMainPController::PlayerSprint()
{
	IPController_MainChar_Interface* IInst = Cast<IPController_MainChar_Interface>(GetPawn());

	if (IInst)
	{
		IInst->PlayerSprintFunction();
	}
}

void AMainPController::PlayerCrouch()
{
	IPController_MainChar_Interface* IInst = Cast<IPController_MainChar_Interface>(GetPawn());

	if (IInst)
	{
		IInst->PlayerCrouchFunction();
	}
}

void AMainPController::PlayerSprintFunction()
{
	// Not relevant for this class.
	// Check MainChar.cpp/h for main implementation.
}

void AMainPController::PlayerCrouchFunction()
{
	// Not relevant for this class.
	// Check MainChar.cpp/h for main implementation.
}