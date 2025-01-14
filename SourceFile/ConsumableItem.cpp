#include "../headerFile/ConsumableItem.h"
#include "../headerFile/Character.h"


//포션100
void potion100::UseItem()
{
	if (GetHealth() <= 100)
	{
		Character::GetInstance()->Healing(100);
	}
}

//절반포션
void potionHalf::UseItem()
{
	if (GetHealth() <= Character::GetInstance()->GetMaxHealth() / 2)
	{
		Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth() / 2);
	}
}