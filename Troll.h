#pragma once
#include "Monster.h"
using namespace std;
class Troll : Monster
{
private:
	string name;
	int health;
	int attack;
public:
	Troll();
	string getName();
	int getHealth();
	void takeDamage(int damage);
	Item* dropItem();

	int getAttack();
};