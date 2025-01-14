#include "../headerFile/GameManager.h"
#include <windows.h>


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
	cout << monster->GetName() << "가 출현했다!" << endl;
	return monster;
}

BossMonster* GameManager::generateBossMonster()
{
	BossMonster* bossmonster = new BossMonster;
	cout << "보스 몬스터 " << bossmonster->GetName() << "가 나타났다!" << endl;
	return bossmonster;
}

void GameManager::battle(Character* player, Monster* monster)
{
	player->StartFight();
	while ((player->GetHealth() >= 0) ^ (monster->GetHealth() >= 0)) // 캐릭터.h에 gethealth 추가
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

//종합
void Start()
{
	GameManager* gameManager = GameManager::GetInstance();
	Character* NameValidation();
	Character* player = Character::GetInstance(); // 캐릭터 생성 로직 변경 필요 혹은 물어보기
	Monster* monster = nullptr;
	BossMonster* bossmonster = nullptr;
	int stage = 1;
	int time = 0;
	while (player->GetLevel() != 10) {
		int ncnt = 0;
		int selectStage = 0;
		while (ncnt == 0)
		{
			cout << "================================" << endl;
			cout << "inGame" << endl;
			//cout << "진행 시간 : " << time << endl;
			cout << "현재 스테이지 : " << stage << endl;
			cout << "================================" << endl;

			cout << "할 행동을 고르시오." << endl;
			cout << "1 : 전투   2 : 상점   3 : 상태보기" << endl;
			cin >> selectStage;
			if (selectStage == 1)
			{
				cout << "1번 선택" << endl;
				Sleep(500);
				cout << "몬스터와 조우!" << endl;
				Sleep(500);

				gameManager->generateMonster();
				gameManager->battle(player, monster);
				ncnt++;
				stage++;
			}
			else if (selectStage == 2)
			{
				//else if 2 이면..
				// //while문으로 한번 더...

				//여기서 다시 분기문
				//index 변수에 입력해서 1 ~ n까지의 아이템 인덱스 입력해서 뭘 살지 입력하고,
				// 플레이어의 골드값과 아이템의 값을 비교하여 살 수 있는지 아닌지 결정
				cout << "2번 선택" << endl;
				Sleep(500);
				cout << "상점 오픈!" << endl;
				Sleep(500);

				//shop의 display 함수 실행
				gameManager->visitShop();
				ncnt++;
			}
			else if (selectStage == 3)
			{
				cout << "3번 선택" << endl;
				Sleep(500);
				cout << "상태보기" << endl;
				Sleep(500);

				gameManager->displayInventory(player);
				//선택창
			}
			else
			{
				cout << "다시 입력해주세요. " << endl;
			}
		}
		Sleep(500);
		system("cls");

		///////////////////////////////////////////////보스
		if (player->GetLevel() == 10)
		{
			while (ncnt == 0)
			{
				cout << "================================" << endl;
				cout << "inGame" << endl;
				//cout << "진행 시간 : " << time << endl;
				cout << "현재 스테이지 : " << stage << endl;
				//cout << "보스 스테이지" << endl;
				cout << "================================" << endl;

				cout << "할 행동을 고르시오." << endl;
				cout << "1 : 전투   2 : 상점   3 : 상태보기" << endl;
				cin >> selectStage;
				if (selectStage == 1)
				{
					cout << "1번 선택" << endl;
					Sleep(500);
					cout << "몬스터와 조우!" << endl;
					Sleep(500);

					gameManager->generateBossMonster();
					gameManager->bossbattle(player, bossmonster);
					//아이템 획득
					ncnt++;
				}
				else if (selectStage == 2)
				{
					cout << "2번 선택" << endl;
					Sleep(500);
					cout << "상점 오픈!" << endl;
					Sleep(500);

					gameManager->visitShop();
					ncnt++;
				}
				else if (selectStage == 3)
				{
					cout << "3번 선택" << endl;
					Sleep(500);
					cout << "상태보기" << endl;
					Sleep(500);

					gameManager->displayInventory(player);
				}
				else
				{
					cout << "다시 입력해주세요. " << endl;
				}
			}
		}
	}
}


