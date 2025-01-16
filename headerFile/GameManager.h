#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <thread> // sleep_for
#include <chrono> // 시간 단위 사용
#include "Monster.h"
#include "Pitta.h"
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
	int stage = 1;
	bool entershop = false;

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
	void tutorialPhase();	//튜토리얼 페이즈
	int firstPhase();		//첫 조우 페이즈
	void BattlePhase();		//전투 페이즈
	void StorePhase();		//상점 페이즈
	void StatusPhase();		//스텟 페이즈
	void EndingPhase();     //엔딩 페이즈
	void Bad_EndingPhase(); //배드 엔딩 페이즈

	void visitShop();
	void battle(Character* player, Monster* monster);
    void bossbattle(Character* player, Monster* bossmonster);
	


	void generateMonster();
	void generateBossMonster();
	void displayInventory(Character* player);
	Monster* getMonster();
};

#endif
