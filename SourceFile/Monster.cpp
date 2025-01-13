#include "../headerFile/Monster.h"


Monster::Monster()
{
	
}

string Monster::GetName()
{
	return name;
}

int Monster::GetHealth()
{
	//monsterDatas.at("Goblin").health;
	//GetRandom(0, 4);
	return health;

}

void Monster::TakeDamage(int damage)
{
	health = health - damage;
}

Item* Monster::DropItem()
{
	Item* item = nullptr;
	return item;
}
