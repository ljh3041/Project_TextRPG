#pragma once
using namespace std;
#include "Monster.h"


class Goblin : public Monster
{
private:
	string name;
	int health;
	int attack;
public:
	Goblin();

	string getName();
	int getHealth();
	void takeDamage(int damage);
	Item* dropItem();

	int getAttack();
};