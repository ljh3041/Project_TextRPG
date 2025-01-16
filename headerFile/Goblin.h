#pragma once
using namespace std;
#include "Monster.h"


class Goblin : public Monster
{
public:
	Goblin() : Monster("Goblin") { name += " 고블린"; species = 1; }
	Goblin(const std::string& _name) : Monster(_name) {}

	Item* GetItem();
};