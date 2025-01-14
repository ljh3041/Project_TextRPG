#pragma once
#include "Monster.h"

using namespace std;

class Troll : public Monster
{
public:
	Troll() : Monster("Troll") { name += " 트롤"; }
	Troll(const std::string& _name) : Monster(_name) {}
};