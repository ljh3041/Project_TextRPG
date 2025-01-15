#include "../headerFile/GameManager.h"
#include "../headerFile/GraphicInterface.h"
#include <windows.h>

GameManager* GameManager::instance = nullptr;
Shop* Shop::instance = nullptr;

//시작, 종료 대화 바꾸기
GameManager::GameManager()
{
	monster = new Monster;
}

GameManager::~GameManager()
{
	delete monster;
}

//Phase
void GameManager::TutorialPhase()
{
	Character::GetInstance()->NameValidation();
	PressAnyKey();
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

void GameManager::BattlePhase()
{
	cout << "1번 선택" << endl;
	Sleep(500);
	cout << "몬스터와 조우!" << endl;
	Sleep(500);

	if (stage < 10)
	{
		GameManager().GetInstance()->generateMonster();
		GameManager().GetInstance()->battle(Character::GetInstance(), GameManager::GetInstance()->getMonster());
		stage++;
	}
	else
	{
		GameManager().GetInstance()->generateMonster();
		GameManager().GetInstance()->battle(Character::GetInstance(), GameManager::GetInstance()->getMonster());
		stage++;
	}

}

void GameManager::StorePhase()
{
	cout << "2번 선택" << endl;
	Sleep(500);
	cout << "상점 오픈!" << endl;
	Sleep(500);
	GameManager().GetInstance()->visitShop();
	PressAnyKey();
}

void GameManager::StatusPhase()
{
	cout << "3번 선택" << endl;
	Sleep(500);
	cout << "상태보기" << endl;
	Sleep(500);

	GameManager::GetInstance()->displayInventory(Character::GetInstance());
	PressAnyKey();

	Character::GetInstance()->DisplayStatus();
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
	monster = new Dragon;
	cout << "보스 몬스터 " << monster->GetName() << "가 나타났다!" << endl;
}


//보스와 일반 몬스터 둘 간의 battle함수의 차이가 거의 없음.
//보스 전투를 다른 방식으로 변경하거나 battle()과 bossbattle()을 합치는 것도 고려.
void GameManager::battle(Character* player, Monster* monster)
{
	player->StartFight(); //인벤토리 아이템 사용 함수
	while ((player->GetHealth() > 0) && (monster->GetHealth() > 0)) // 캐릭터.h에 gethealth 추가
	{
		player->UseItem(); // 플레이어 무조건 선턴. 아이템 먼저 사용.
		//플레이어 공격
		printPlayer();
		cout << player->GetName() << "의 공격! " << player->GetAttack() << "의 피해" << endl;
		Sleep(500);
		monster->TakeDamage(player->GetAttack());
		cout << monster->GetName() << "의 남은 체력 " << monster->GetHealth() << endl;
		Sleep(1000);

		if (monster->GetHealth() <= 0) // 몬스터가 공격하기 전 이미 피가 0 이하면 전투 종료.
		{
			break;
		}

		//몬스터 공격
		printBoss();
		cout << monster->GetName() << "의 공격! " << monster->GetAttack() << "의 피해" << endl;
		Sleep(500);
		player->TakeDamage(monster->GetAttack());
		cout << player->GetName() << "의 남은 체력 " << player->GetHealth() << endl;
		Sleep(1000);
		//useitem?
	}
	//둘 중 하나의 체력이 0 이하가 되어도 남은 공격 기회는 반드시 사용하는 경우를 수정.

	player->EndFight(); //인벤토리 아이템 사용 함수


	if (monster->GetHealth() <= 0) // 플레이어 승리 시 if 문 내에서 함수 종료후 메인으로
	{
		cout << "승리" << endl;
		player->LevelUp(); // 플레이어 레벨 업 함수 적용
		PressAnyKey();
		
		//item 획득 함수;
	}
	else // 플레이어 패배 시 종료
	{
		cout << "패배" << endl;
		exit(0);
	}
}

void GameManager::bossbattle(Character* player, Monster* bossmonster)
{
	player->StartFight();
	while ((player->GetHealth() > 0) && (bossmonster->GetHealth() > 0))
	{
		player->UseItem();  // 플레이어 무조건 선턴. 아이템 먼저 사용.

		//플레이어 공격
		cout << player->GetName() << "의 공격! " << player->GetAttack() << "의 피해" << endl;
		Sleep(500);
		bossmonster->TakeDamage(player->GetAttack());
		cout << bossmonster->GetName() << "의 남은 체력 " << bossmonster->GetHealth() << endl;
		Sleep(1000);

		if (bossmonster->GetHealth() <= 0) // 몬스터가 공격하기 전 이미 피가 0 이하면 전투 종료.
		{
			break;
		}

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
		//골드 획득 함수;
		int gold = 0;
		player->SetGold(gold);
		exit(0);
	}
	else
	{
		cout << "패배" << endl;
		exit(0);
	}
}


//반드시 Shop 방문 함수를 GameManager에서 제어해야 하는가?
void GameManager::visitShop()//Character* player)
{
	Shop::GetInstance()->EnterShop();
	Shop::GetInstance()->ShopSelection();
}

void GameManager::displayInventory(Character* player)
{
	player->DisplayStatus();
}

Monster* GameManager::getMonster()
{
	return monster;
}
