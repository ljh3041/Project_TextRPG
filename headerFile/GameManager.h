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


GameManager* GameManager::instance = nullptr;

//시작, 종료 대화 바꾸기
GameManager::GameManager()
{
	cout << "TMI 시작" << endl;
}

GameManager::~GameManager()
{
	cout << "종료" << endl;
}

//몬스터 랜덤 소환
Monster* GameManager::generateMonster()
{
	Monster* monster = nullptr;
	int type = rand() % 3; // 0, 1, 2 중 랜덤 선택 (Goblin, Orc, Troll)
	switch (type) {
	case 0:
		monster = new Goblin();
		break;
	case 1:
		monster = new Orc();
		break;
	case 2:
		monster = new Troll();
		break;
	}
	cout << monster << "가 출현했다!" << endl;
	return monster;
}

BossMonster* GameManager::generateBossMonster()
{
	BossMonster* monster = new BossMonster;
	cout << "보스 몬스터 " << monster << "가 나타났다!" << endl;
	return monster;
}

void GameManager::battle(Character* player, Monster* monster)
{
	while (player->gethealth() != 0 || monster->GetHealth() != 0) // 캐릭터.h에 gethealth 추가
	{
		//플레이어 공격
		cout << player->getname() << "의 공격! " << player->getattack() << "의 피해" << endl;
		this_thread::sleep_for(chrono::seconds(1 / 2));
		monster->TakeDamage(player->getattack());
		cout << monster->GetName() << "의 남은 체력 " << monster->GetHealth() << endl;
		this_thread::sleep_for(chrono::seconds(1));
		//몬스터 공격
		cout << monster->GetName() << "의 공격! " << monster->GetAttack() << "의 피해" << endl;
		this_thread::sleep_for(chrono::seconds(1 / 2));
		player->TakeDamage(monster->GetAttack());
		cout << player->getname() << "의 남은 체력 " << player->gethealth() - monster->GetAttack() << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void GameManager::visitShop(Character* player)
{
	char visit;
	int shopcnt = 0;
	cout << "상점에 방문하시겠습니까? Y / N" << endl;
	cin >> visit;
	while (shopcnt == 0) {
		if (visit == 'Y' || visit == 'y')
		{
		//	player->visitShop();
			shopcnt++;
		}
		else if (visit == 'N' || visit == 'n')
		{
			cout << "공백?" << endl;
			shopcnt++;
		}
	}

}

void GameManager::displayInventory(Character* player)
{
	cout << "(플레이어 이름)의 상태" << endl << "체력 : " << player->gethealth() << endl << "공격력 : " << endl << " 경험치 : " << endl << "골드 : " << endl; //캐릭터 - 골드 
	//or
	//cout << player->displayStatus();
}

//종합
void StartGame()
{
	//GameManager* gameManager = GameManager::GetInstance();
	//Character* player = Character::GetInstance();
	Monster* monster = nullptr;
	BossMonster* bossMonster = new BossMonster;
	/*
	while (player->getlevel() != 10) { // 캐릭터.h에 getlevel 추가
		gameManager->generateMonster();
		gameManager->battle(player, monster);
		gameManager->displayInventory(player);
		gameManager->visitShop(player);
	}
	gameManager->generateBossMonster();
	gameManager->battle(player, monster);
	*/
	cout << "승리했습니다! " << endl;
}


#endif