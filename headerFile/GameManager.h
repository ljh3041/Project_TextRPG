#pragma once
#include "Monster.h"
#include "BossMonster.h"
#include "Character.h"

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
	void visitShop(Character* player);
	void displayInventory(Character* player);
};