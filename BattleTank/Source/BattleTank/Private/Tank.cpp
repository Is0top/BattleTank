// Copyright Yuri Khromov


#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Fire()
{
	if (!ensure(MyBarrel)) { return; }
	
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (bIsReloaded)
	{
		// Spawn a projectile at MyBarrel socket location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			MyBarrel->GetSocketLocation(FName("Projectile")),
			MyBarrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}