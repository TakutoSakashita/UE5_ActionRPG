#include "DataAssets/Input/DataAsset_InputConfig.h"

/// タグによるネイティブ入力アクションの検索
/// @param InInputTag 
/// @return 
UInputAction* UDataAsset_InputConfig::FindNativeinputActionBuTag(const FGameplayTag& InInputTag) const
{
	for(const FWarriorInputActionConfig& InputActionConfig : NativeInputActions)
	{
		//入力アクションconfigドット入力タグが、この入力タグnの入力と等しいかどうか
		if(InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}
	
	return nullptr;
}
