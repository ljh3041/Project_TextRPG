#include "Troll.h"

Troll::Troll()
{
	name = "";
	health = 0;
	attack = 0;
}

string Troll::getName()
{
	return name;
}
int Troll::getHealth()
{
	return health;
}
void Troll::takeDamage(int damage)
{
	health = health - damage;
}
Item* Troll::dropItem()
{
	Item* item = nullptr;
	return item;
}

int Troll::getAttack()
{
	return attack;
}