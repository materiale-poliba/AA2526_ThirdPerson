#include "BasePickup.h"

#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"

ABasePickup::ABasePickup()
{
	PrimaryActorTick.bCanEverTick = false;
	
	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootComponent = ArrowComp;
	ArrowComp->ArrowColor = FColor::Yellow;
	ArrowComp->ArrowLength = 200.f;
	
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereComp->SetupAttachment(RootComponent);
	SphereComp->SetSphereRadius(500.f);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	SphereComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::HandlePickupDelegate);
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComp->SetupAttachment(SphereComp);
}

void ABasePickup::HandlePickupDelegate(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Pickup overlapped by %s"), *OtherActor->GetName());
	// Tutti i check del caso
	// Se sono passati, eseguo il pickup effettivo
	HandlePickup();
}

void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

