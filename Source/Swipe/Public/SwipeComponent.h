// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "SwipeComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwipeUpDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwipeDownDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwipeLeftDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwipeRightDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SWIPE_API USwipeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USwipeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Swipe")
	void TouchBegin();
	UFUNCTION(BlueprintCallable, Category = "Swipe")
	void TouchEnd();
		
	UPROPERTY(BlueprintAssignable, Category = "Swipe")
	FSwipeUpDelegate OnSwipeUp;
	UPROPERTY(BlueprintAssignable, Category = "Swipe")
	FSwipeDownDelegate OnSwipeDown;
	UPROPERTY(BlueprintAssignable, Category = "Swipe")
	FSwipeLeftDelegate OnSwipeLeft;
	UPROPERTY(BlueprintAssignable, Category = "Swipe")
	FSwipeRightDelegate OnSwipeRight;

public:
	// Amount, exceeding which triggering swipe event. Default value 50 units
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Swipe")
	float SwipeDistance;
	// Delta time which triggering swipe event. Default value 0.2 sec
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Swipe")
	float SwipeTriggerTime;
private:
	bool bTouched;
	FVector2D TouchStartLocation;
	FVector2D TouchEndLocation;
	bool bSwipeTriggered;
	bool bSwipeEnded;
	float SwipeTime;
	float SwipeStartTime;
	float SwipeEndTime;

	void CheckSwipe();

	FVector2D GetTouchCoordinates();
};
