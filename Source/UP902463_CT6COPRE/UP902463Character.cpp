// Fill out your copyright notice in the Description page of Project Settings.


#include "UP902463Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AUP902463Character::AUP902463Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArm->TargetArmLength = 350.f;
	CameraArm->SocketOffset = FVector(0.f, 0.f, 100.f);
	CameraArm->bUsePawnControlRotation = true;
	CameraArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = false;
	Camera->SetupAttachment(CameraArm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void AUP902463Character::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AUP902463Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator ControlRot = GetControlRotation();

	ControlRot.Roll = 0.f;
	ControlRot.Pitch = 0.f;
	
	AddMovementInput(ControlRot.Vector());
}

// Called to bind functionality to input
void AUP902463Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AUP902463Character::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AUP902463Character::StopJumping);

	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &AUP902463Character::MoveLeft);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &AUP902463Character::MoveRight);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &AUP902463Character::MoveDown);
}

void AUP902463Character::MoveLeft()
{
	UE_LOG(LogTemp, Warning, TEXT("Move Left"));
}

void AUP902463Character::MoveRight()
{
	UE_LOG(LogTemp, Warning, TEXT("Move Right"));
}

void AUP902463Character::MoveDown()
{
	UE_LOG(LogTemp, Warning, TEXT("Move Down"));
}
