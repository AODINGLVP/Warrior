// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimiInstances/Hero/WarriorHeroLinkedAnimLayer.h"
#include "AnimiInstances/Hero/WarriorHerorAnimInstance.h"

UWarriorHerorAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorHerorAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
