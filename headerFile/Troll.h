#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
	Troll() : Monster("Troll") { name += " 트롤"; species = 2; }
	Troll(const std::string& _name) : Monster(_name) {}

	Item* GetItem();
};