// Fill out your copyright notice in the Description page of Project Settings.


#include "MainChar.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMainChar::AMainChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmThirdPersonView = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Third Person"));
	SpringArmThirdPersonView->SetupAttachment(RootComponent);

	PlayerThirdPersonView = CreateDefaultSubobject<UCameraComponent>(TEXT("Third Person Camera"));
	PlayerThirdPersonView->SetupAttachment(SpringArmThirdPersonView);

	// Set this Character to be able to Crouch by default and other properties defined here
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetCharacterMovement()->SetCrouchedHalfHeight(78.0f);

	// Gets and Sets the default MaxWalkSpeed of this character for later usage, i.e. Sprinting, Dashing, etc
	DefaultMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;

	// Sets some important defaults for the SpringArmThirdPersonView
	SpringArmThirdPersonView->bUsePawnControlRotation = true;
	SpringArmThirdPersonView->SetRelativeLocation(FVector(-90.0f, 0.0f, 90.0f));
}

// Called when the game starts or when spawned
void AMainChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainChar::PlayerCrouchFunction()
{
	if (!bIsCrouched)
	{
		Crouch();
	}
	else
	{
		UnCrouch();
	}
}

void AMainChar::PlayerSprintFunction()
{
	float TempMaxWSpd = GetCharacterMovement()->MaxWalkSpeed;
	if (TempMaxWSpd > DefaultMaxWalkSpeed)
	{
		GetCharacterMovement()->MaxWalkSpeed = DefaultMaxWalkSpeed;
	}
	else if (!bIsCrouched)
	{
		GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
	}
}
