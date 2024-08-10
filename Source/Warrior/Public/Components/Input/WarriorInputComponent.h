#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject,typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,const FGameplayTag& InInputTag,
		ETriggerEvent TriggerEvent,UserObject* ContextObject, CallbackFunc func);
};

template <class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc func)
{
	checkf(InInputConfig,TEXT("Input config data asset is null,can not procced with binding"));

	if(UInputAction* FoundAction = InInputConfig->FindNativeinputActionBuTag(InInputTag))
	{
		BindAction(FoundAction,TriggerEvent,ContextObject,func);
	}
}
