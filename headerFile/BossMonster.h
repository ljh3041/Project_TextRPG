#pragma once
#include "Monster.h"

using namespace std;

class BossMonster : public Monster
{
public:
	BossMonster() : Monster("BossMonster") {}
	BossMonster(const std::string& _name) : Monster(_name) {}
	
};