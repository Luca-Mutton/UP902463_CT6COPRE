// Fill out your copyright notice in the Description page of Project Settings.


#include "UP902463Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UP902463_CT6COPREGameMode.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>



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

	CT6COPREGameMode = Cast<AUP902463_CT6COPREGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	check(CT6COPREGameMode);
	
}




void AUP902463Character::AddCoin()
{

	CT6COPREGameMode->AddCoin();
}

void AUP902463Character::UpdateDistance()
{
	CT6COPREGameMode->AddDistance();
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


void AUP902463Character::ChangeLaneUpdate(const float Value)
{
	FVector Location = GetCapsuleComponent()->GetComponentLocation();
	Location.Y = FMath::Lerp(CT6COPREGameMode->LaneSwitchValue[CurrentLane], CT6COPREGameMode->LaneSwitchValue[NextLane], Value);
	SetActorLocation(Location);
}

void AUP902463Character::ChangeLaneFinished()
{
	CurrentLane = NextLane;
}

void AUP902463Character::Death()
{
	UWorld* World = GetWorld();

	if (!bIsDead)
	{
		if (World)
		{
			bIsDead = true;
			DisableInput(nullptr);

			GetMesh()->SetVisibility(false);
			World->GetTimerManager().SetTimer(RestartTimerHandle, this, &AUP902463Character::OnDeath, 1.f);
		}
	}

	
	
}

void AUP902463Character::OnDeath()
{
	bIsDead = false;

	if (RestartTimerHandle.IsValid())
	{
		GetWorldTimerManager().ClearTimer(RestartTimerHandle);
	}

	UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), TEXT("RestartLevel"));
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
	NextLane = FMath::Clamp(CurrentLane - 1, 0, 2);
	ChangeLane();
}

void AUP902463Character::MoveRight()
{
	NextLane = FMath::Clamp(CurrentLane + 1, 0, 2);
	ChangeLane();
}

void AUP902463Character::MoveDown()
{
	static FVector Impulse = FVector(0, 0, MoveDownImpulse);

	GetCharacterMovement()->AddImpulse(Impulse, true);
}
