#pragma once
using namespace std;
#include "Monster.h"


class Goblin : public Monster
{
public:
	Goblin() : Monster("Goblin") {}
	Goblin(const std::string& _name) : Monster(_name) {}
};