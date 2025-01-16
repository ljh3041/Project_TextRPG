#pragma once
#include "Monster.h"

using namespace std;

class Pitta : public Monster
{
public:
	Pitta() : Monster("Pitta") { name += " 팔색조";}
	Pitta(const std::string& _name) : Monster(_name) {}
	Item* GetItem();
};