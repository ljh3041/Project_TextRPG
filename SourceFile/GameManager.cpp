#include "../headerFile/GameManager.h"
#include <windows.h>
#include <conio.h>



GameManager* GameManager::instance = nullptr;

//시작, 종료 대화 바꾸기
GameManager::GameManager()
{

	monster = new Monster;
}

GameManager::~GameManager()
{
	delete monster;
}

//몬스터 랜덤 소환
void GameManager::generateMonster()
{
	delete monster;
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
	monster;
	cout << monster->GetName() << "가 출현했다!" << endl;
}

void GameManager::generateBossMonster()
{
	delete monster;
	monster = new BossMonster;
	cout << "보스 몬스터 " << monster->GetName() << "가 나타났다!" << endl;
}

void GameManager::battle(Character* player, Monster* monster)
{
	player->StartFight();
	monster;
	while ((player->GetHealth() > 0) && (monster->GetHealth() > 0)) // 캐릭터.h에 gethealth 추가
	{
		player->UseItem();
		//플레이어 공격
		cout << player->GetName() << "의 공격! " << player->GetAttack() << "의 피해" << endl;
		Sleep(500);
		monster->TakeDamage(player->GetAttack());
		cout << monster->GetName() << "의 남은 체력 " << monster->GetHealth() << endl;
		Sleep(1000);
		//몬스터 공격
		cout << monster->GetName() << "의 공격! " << monster->GetAttack() << "의 피해" << endl;
		Sleep(500);
		player->TakeDamage(monster->GetAttack());
		cout << player->GetName() << "의 남은 체력 " << player->GetHealth() - monster->GetAttack() << endl;
		Sleep(1000);
		//useitem?
	}
	player->EndFight();
	if (monster->GetHealth() <= 0)
	{
		cout << "승리" << endl;
		player->LevelUp();
		int i = 0;
		i = _getch();
		//item 획득 함수;
	}
	else
	{
		cout << "패배" << endl;
		exit(0);
	}
}

void GameManager::bossbattle(Character* player, BossMonster* bossmonster)
{
	player->StartFight();
	while ((player->GetHealth() <= 0) ^ (bossmonster->GetHealth() <= 0))
	{
		player->UseItem();
		//플레이어 공격
		cout << player->GetName() << "의 공격! " << player->GetAttack() << "의 피해" << endl;
		Sleep(500);
		bossmonster->TakeDamage(player->GetAttack());
		cout << bossmonster->GetName() << "의 남은 체력 " << bossmonster->GetHealth() << endl;
		Sleep(1000);
		//보스 몬스터 공격
		cout << bossmonster->GetName() << "의 공격! " << bossmonster->GetAttack() << "의 피해" << endl;
		Sleep(500);
		player->TakeDamage(bossmonster->GetAttack());
		cout << player->GetName() << "의 남은 체력 " << player->GetHealth() - bossmonster->GetAttack() << endl;
		Sleep(1000);
	}
	player->EndFight();
	if (bossmonster->GetHealth() <= 0)
	{
		cout << "승리" << endl;
		//item 획득 함수;
		exit(0);
	}
	else
	{
		cout << "패배" << endl;
		exit(0);
	}
}

int GameManager::firstPhase()
{
	system("cls");
	cout << "================================" << endl;
	cout << "inGame" << endl;
	cout << "현재 스테이지 : " << stage << endl;
	cout << "================================" << endl;

	cout << "할 행동을 고르시오." << endl;
	cout << "1 : 전투   2 : 상점   3 : 상태보기" << endl;
	int value;
	cin >> value;
	return value;
}

void GameManager::visitShop()//Character* player)
{
	Shop* shop = new Shop;
	shop->EnterShop();
	shop->ShopSelection();
}

void GameManager::displayInventory(Character* player)
{
	player->DisplayStatus();
}

Monster* GameManager::getMonster()
{
	return monster;
}
