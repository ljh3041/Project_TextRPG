#pragma once
#include "Monster.h"

using namespace std;

class BossMonster : public Monster
{
public:
	BossMonster() : Monster("BossMonster") { name += " 드래곤"; health = static_cast<int>(health * GetRandomf(1, 1.5)); attack = static_cast<int>(attack * GetRandomf(1, 1.5)); }
	BossMonster(const std::string& _name) : Monster(_name) {}
};