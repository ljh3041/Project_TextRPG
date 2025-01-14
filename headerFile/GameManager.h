#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <thread> // sleep_for
#include <chrono> // 시간 단위 사용
#include "Monster.h"
#include "BossMonster.h"
#include "Character.h"
#include "Orc.h"
#include "Troll.h"
#include "Goblin.h"
#include "Shop.h"

using namespace std;

//Singleton Pattern
class GameManager
{
private:
	static GameManager* instance;

	GameManager();
	~GameManager();
	
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

public:
	static GameManager* GetInstance() {
		if (instance == nullptr) {
			instance = new GameManager();
		}
		return instance;
	}

	Monster* generateMonster();
	BossMonster* generateBossMonster();
	void battle(Character* player, Monster* monster);
    void bossbattle(Character* player, BossMonster* bossmonster);
	void visitShop();
	void displayInventory(Character* player);
};

#endif
