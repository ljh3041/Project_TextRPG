#pragma once
#include "Monster.h"

using namespace std;

class Dragon : public Monster
{
public:
	Dragon() : Monster("Dragon") { name += " 드래곤"; health = static_cast<int>(health * GetRandomf(1, 1.5)); attack = static_cast<int>(attack * GetRandomf(1, 1.5)); }
	Dragon(const std::string& _name) : Monster(_name) {}
};