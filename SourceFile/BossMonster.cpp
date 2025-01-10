#include "../headerFile/BossMonster.h"

BossMonster::BossMonster()
{
	name = "";
	health = 0;
	attack = 0;
}

string BossMonster::getName()
{
	return name;
}
int BossMonster::getHealth()
{
	return health;
}
void BossMonster::takeDamage(int damage)
{
	health = health - damage;
}
Item* BossMonster::dropItem()
{
	Item* item = nullptr;
	return item;
}

int BossMonster::getAttack()
{
	return attack;
}