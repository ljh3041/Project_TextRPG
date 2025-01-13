#pragma once
#include <string>
#include <random>
#include "Item.h"
#include "MyMath.h"
#include "MonsterData.h"

using namespace std;
class Monster
{

protected:
	string name = "";	//이름
	int health = 0;		//체력
	int attack = 0;		//공격력

public:
	string GetName();
	int GetHealth();

	void TakeDamage(int damage);
	Item* DropItem();
};