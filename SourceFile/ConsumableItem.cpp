#include "../headerFile/ConsumableItem.h"
#include "../headerFile/Character.h"

Character* c;

//포션100
void potion100::UseItem()
{
	if (c->GetHealth() <= 100)
	{
		c->Healing(100);
	}
}

//절반포션
void potionHalf::UseItem()
{
	if (c->GetHealth() <= c->GetMaxHealth() / 2)
	{
		c->Healing(c->GetMaxHealth() / 2);
	}
}