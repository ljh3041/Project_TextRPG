#pragma once
#include <string>
#include "Item.h"
#include "Character.h"
#include "MonsterData.h"
#include "MyMath.h"
#include "DecoWord.h"

using namespace std;

class Monster
{

protected:
	string name = "";	//이름
	int health = 0;		//체력
	int attack = 0;		//공격력

public:
	Monster() {};
	Monster(string _name);
	string GetName();
	int GetHealth();
	int GetAttack();
	int GetRandomHealthStat(string _name);
	int GetRandomAttackStat(string _name);
	void TakeDamage(int damage);
	Item* DropItem();

};

