#include "BasePickup.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"

ABasePickup::ABasePickup()
{
	// This pickup is fully event-driven (overlap callback), so no per-frame Tick is needed.
	PrimaryActorTick.bCanEverTick = false;
	
	// Root marker used mainly for orientation/placement in the editor.
	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootComponent = ArrowComp;
	ArrowComp->ArrowColor = FColor::Yellow;
	ArrowComp->ArrowLength = 200.f;
	
	// Trigger volume that detects when a pawn enters pickup range.
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereComp->SetupAttachment(RootComponent);
	SphereComp->SetSphereRadius(500.f);

	// Overlap-only collision profile:
	// - QueryOnly: no physics collision/response
	// - ObjectType set to WorldStatic (classification)
	// - Ignore all channels except Pawn, which overlaps
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	SphereComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	
	// Bind overlap begin event to pickup handler.
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::HandlePickupDelegate);
	
	// Visual representation of the pickup.
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComp->SetupAttachment(SphereComp);
}

void ABasePickup::HandlePickupDelegate(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Pickup overlapped by %s"), *OtherActor->GetName());

	// TODO: Validate overlap before granting pickup, e.g.:
	// - OtherActor is valid and is the expected character/pawn type
	// - pickup is still available (not already consumed)
	// - optional authority check for multiplayer (HasAuthority / server-side logic)
	//
	// If validation passes, execute the actual pickup behavior.
	HandlePickup();
}

void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}