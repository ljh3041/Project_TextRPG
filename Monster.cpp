#include "Monster.h"
#include <string>



string Monster::getName()
{
	return name;
}
int Monster::getHealth()
{
	return health;
}
void Monster::takeDamage(int damage)
{
	health = health - damage;
}
Item* Monster::dropItem()
{
	Item* item = nullptr;
	return item;
}