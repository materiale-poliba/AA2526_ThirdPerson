#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

class UArrowComponent;
class USphereComponent;

/**
 * Base actor for overlap-driven pickups.
 * Detects a pawn entering range, then forwards behavior to Blueprint via HandlePickup().
 */
UCLASS()
class AA2526_THIRDPERSON_API ABasePickup : public AActor
{
	GENERATED_BODY()

protected:
	// Editor-facing orientation root (useful for placement and facing).
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UArrowComponent* ArrowComp;

	// Trigger volume used to detect nearby actors (typically pawns).
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	USphereComponent* SphereComp;

	// Visual mesh shown for this pickup.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

public:
	// Sets up components and overlap wiring.
	ABasePickup();

	/**
	 * Bound to SphereComp begin-overlap.
	 * Receives Unreal overlap context and then delegates pickup logic to HandlePickup().
	 */
	UFUNCTION()
	void HandlePickupDelegate(
		UPrimitiveComponent* OverlappedComponent, // Component that generated the overlap (SphereComp).
		AActor* OtherActor,                        // Actor that entered the trigger.
		UPrimitiveComponent* OtherComp,            // Specific component on OtherActor that overlapped.
		int32 OtherBodyIndex,                      // Body index for multi-body components.
		bool bFromSweep,                           // True if overlap came from movement sweep.
		const FHitResult& SweepResult);            // Detailed hit result when bFromSweep is true.

	/**
	 * Blueprint hook for concrete pickup behavior
	 * (e.g., grant item, play VFX/SFX, destroy actor).
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void HandlePickup();

protected:
	// Standard Unreal lifecycle entry point.
	virtual void BeginPlay() override;
};
