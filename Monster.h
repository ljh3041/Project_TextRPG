#pragma once

#include <string>
#include "Item.h"

using namespace std;
class Monster
{
private:
	string name;
	int health;
	int attack;
public:
	string getName();
	int getHealth();
	void takeDamage(int damage);
	Item* dropItem();

	//순수가상함수
	//공격 횟수나 방식은 몬스터마다 다르게...
	virtual int getAttack() = 0;
};