#pragma once
#include "Monster.h"

using namespace std;

class BossMonster : public Monster
{
public:
	BossMonster() {}// : Monster("BossMonster") { name += " 드래곤"; }
	BossMonster(const std::string& _name) : Monster(_name) {}
};