#pragma once
#include <iostream>
#include "Monster.h"

using namespace std;

class Orc : public Monster
{

public:
	Orc() {}// : Monster("Orc") { name += " 오크"; }
	Orc(const std::string& _name) : Monster(_name) {}
};