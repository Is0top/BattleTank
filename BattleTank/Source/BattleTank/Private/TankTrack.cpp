// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

//void UTankTrack::BeginPlay()
//{
//	Super::BeginPlay();
//	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
//}
//void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//}

//void UTankTrack::ApplySidewaysForce()
//{
//	// Work-out the required acceleration for this frame to correct slipping
//	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
//	auto DeltaTime = GetWorld()->GetDeltaSeconds();
//	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
//
//	// Calculate and apply sideways force (F = m * a)
//	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
//	auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; // (!)there are two tracks
//	TankRoot->AddForce(CorrectionForce);
//}

void UTankTrack::SetThrottle(float Throttle)
{
	//CurrentThrottle += Throttle;
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1.0, 1.0);
	DriveTrack(CurrentThrottle);
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for (USceneComponent* Child : Children)
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) continue;
		
		AActor* SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SprungWheel = Cast<ASprungWheel>(SpawnedChild);
		if (!SprungWheel) continue;

		ResultArray.Add(SprungWheel);
	}
	return ResultArray;
}

void UTankTrack::DriveTrack(float Throttle)
{
	auto ForceApplied = Throttle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (ASprungWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}

//	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
//	auto ForceLocation = GetComponentLocation();
//	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
//	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

//void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
//{
//	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle, -1.0, 1.0);
//	DriveTrack();
//	ApplySidewaysForce();
//	CurrentThrottle = 0.0f;
//}