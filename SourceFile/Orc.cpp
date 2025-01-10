#include "../headerFile/Orc.h"

Orc::Orc()
{
	name = "";
	health = 0;
	attack = 0;
}

string Orc::getName()
{
	return name;
}
int Orc::getHealth()
{
	return health;
}
void Orc::takeDamage(int damage)
{
	health = health - damage;
}
Item* Orc::dropItem()
{
	Item* item = nullptr;
	return item;
}

int Orc::getAttack()
{
	return attack;
}