#pragma once
#include <iostream>
#include "Monster.h"


class Orc : public Monster
{

public:
	Orc() : Monster("Orc") { name += " 오크"; species = 3; }
	Orc(const std::string& _name) : Monster(_name) {}
	Item* GetItem();
};