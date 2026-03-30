// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

class UArrowComponent;
class USphereComponent;

UCLASS()
class AA2526_THIRDPERSON_API ABasePickup : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
//	TObjectPtr<UArrowComponent> ArrowComp;
	UArrowComponent* ArrowComp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	USphereComponent* SphereComp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

public:
	// Sets default values for this actor's properties
	ABasePickup();

	UFUNCTION()
	void HandlePickupDelegate(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void HandlePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
