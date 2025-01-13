#pragma once

#include "Monster.h"
using namespace std;
class Orc : public Monster
{

public:
	Orc() : Monster("Orc") {}
	Orc(const std::string& _name) : Monster(_name) {}
};