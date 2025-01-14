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
	Monster* monster = nullptr;
	int stage = 0;

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

	//게임 페이즈
	int firstPhase();
	void visitShop();
	void battle(Character* player, Monster* monster);
    void bossbattle(Character* player, BossMonster* bossmonster);


	void generateMonster();
	void generateBossMonster();
	void displayInventory(Character* player);
	Monster* getMonster();
};

#endif
