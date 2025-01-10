#pragma once
#include "Monster.h"

using namespace std;

class BossMonster : Monster
{
private:
	string name;
	int health;
	int attack;
public:
	BossMonster();
	string getName();
	int getHealth();
	void takeDamage(int damage);
	Item* dropItem();

	int getAttack();
};