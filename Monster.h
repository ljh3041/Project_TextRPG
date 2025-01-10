#pragma once
#include <string>
#include <random>
#include "Item.h"

using namespace std;
class Monster
{
	enum MonstetrKind	//굳이 클래스를 나눠가며 할 필요가..?
	{
		Goblin,
		Troll,
		Orc,
		Dragon
	};

protected:
	string name;	//이름
	int health;		//체력
	int attack;		//공격력
	MonstetrKind species;


public:
	string GetName();
	int GetHealth();
	int GetRandom(int _min, int _max);	//랜덤 정수 받기
	
	void SettingStateInit(MonstetrKind _monsterkind);
	void TakeDamage(int damage);
	Item* DropItem();
	string SpeciesToString(MonstetrKind _monsterkind);	//종 종류 문자열로 전환

};