#include "Goblin.h"

Goblin::Goblin()
{
	name = "";
	health = 0;
	attack = 0;
}

string Goblin::getName()
{
	return name;
}
int Goblin::getHealth()
{
	return health;
}
void Goblin::takeDamage(int damage)
{
	health = health - damage;
}
Item* Goblin::dropItem()
{
	Item* item = nullptr;
	return item;
}

int Goblin::getAttack()
{
	return attack;
}