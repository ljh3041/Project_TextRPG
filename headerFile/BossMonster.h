#pragma once
#include "Monster.h"

using namespace std;

class BossMonster : public Monster
{
public:
<<<<<<< Updated upstream
	BossMonster() {}// : Monster("BossMonster") { name += " 드래곤"; }
=======
	BossMonster() : Monster("BossMonster") { name += " 드래곤"; health *= GetRandomf(1, 1.5); attack *= GetRandomf(1, 1.5); }
>>>>>>> Stashed changes
	BossMonster(const std::string& _name) : Monster(_name) {}
};