#pragma once
#include "Monster.h"
using namespace std;
class Troll : public Monster
{
public:
	Troll() : Monster("Troll") {}
	Troll(const std::string& _name) : Monster(_name) {}
	
};