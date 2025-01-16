#include "../headerFile/GameManager.h"
#include "../headerFile/GraphicInterface.h"
#include "../headerFile/TextColor.h"
#include <limits>

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
void GameManager::tutorialPhase()
{
	int i = 0;
	printLoding4();
	Sleep(1000);
	system("cls");
	while (i == 0)
	{
		printLoding3();
		Sleep(1000);
		system("cls");
		if (_kbhit()) {
			_getch(); // 키 입력을 받음 (입력된 키는 무시)
			break;
		}
		printLoding4();
		Sleep(1000);
		system("cls");
		if (_kbhit()) {
			_getch(); // 키 입력을 받음 (입력된 키는 무시)
			break;
		}// 루프 종료
	}

	//showTeamName();

	Character::GetInstance()->NameValidation();
	Sleep(500);
	soundTrack1();
	PressAnyKey();

}

int GameManager::firstPhase()
{
	int value;
	while (true) {
		system("cls");
		cout << "================================" << endl;
		cout << "inGame" << endl;
		cout << "현재 스테이지 : " << stage << endl;
		cout << "================================" << endl;

		cout << "할 행동을 고르시오." << endl;
		cout << "1 : 전투   2 : 상점   3 : 상태보기" << endl;
		cin >> value;
		if (cin.fail()) {
			cin.clear(); // 오류 상태를 초기화
			cin.ignore(100, '\n');
			cout << "다시 입력해주세요. " << endl;
			cout << "\n▶Press Anykey";
			PressAnyKey();
		}
		else {
			cin.ignore(100, '\n');
			break;
		}
	}
	return value;
}

void GameManager::BattlePhase()
{
	cout << "1번 선택" << endl;
	Sleep(500);
	cout << "몬스터와 조우!" << endl;
	Sleep(500);

	if (stage < 11)
	{
		GameManager::GetInstance()->generateMonster();
		GameManager::GetInstance()->battle(Character::GetInstance(), GameManager::GetInstance()->getMonster());
		stage++;
	}
	else
	{
		//한번에 battle함수로만 컨트롤 하고, monster generate에서 bossmonster를 생성하는 것도 
		GameManager::GetInstance()->generateBossMonster();
		GameManager::GetInstance()->bossbattle(Character::GetInstance(), GameManager::GetInstance()->getMonster());
	}
}

void GameManager::StorePhase()
{
	cout << "2번 선택" << endl;
	Sleep(500);
	cout << "상점 오픈!" << endl;
	Sleep(500);

	GameManager::GetInstance()->visitShop();
}

void GameManager::StatusPhase()
{
	cout << "3번 선택" << endl;
	Sleep(500);
	cout << "상태보기" << endl;
	Sleep(500);

	GameManager::GetInstance()->displayInventory(Character::GetInstance());
	PressAnyKey();
}

void GameManager::EndingPhase()
{
	system("cls");
	int speed = 500;
	Sleep(speed * 3);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                               'TMI 팔색조 (이)가 조용해졌다.'" << endl;
	Sleep(speed * 3);
	system("cls");
	Sleep(speed * 3);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                                  '세상이 조용해졌다.'" << endl;
	Sleep(speed * 3);
	cout << "\n\n\n\n\n                                                          Fin." << endl;
	Sleep(speed * 5);
	system("cls");
	Sleep(speed * 3);
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
	//monster;
	cout << red << monster->GetName() << white << "(이)가 출현했다!" << endl;
	PressAnyKey();

}

void GameManager::generateBossMonster()
{
	delete monster;
	monster = new Pitta;
	cout << "보스 몬스터 " << monster->GetName() << "가 나타났다!" << endl;
	PressAnyKey();
}

//보스와 일반 몬스터 둘 간의 battle함수의 차이가 거의 없음.
//보스 전투를 다른 방식으로 변경하거나 battle()과 bossbattle()을 합치는 것도 고려.
void GameManager::battle(Character* player, Monster* monster)
{
	Shop::GetInstance()->InitializeShop();
	player->StartFight(); //인벤토리 아이템 사용 함수
	while ((player->GetHealth() > 0) && (monster->GetHealth() > 0)) // 캐릭터.h에 gethealth 추가
	{
		system("cls");
		printPlayer();
		cout << endl << endl << endl << endl << endl;
		Sleep(100);
		system("cls");

		int randomValue = rand() % 100;

		if (randomValue >= 0 && randomValue <= 94)
		{
			int P_dam = player->GetRandTotalAttack();
			monster->TakeDamage(P_dam);
			printPlayer();
			cout << player->GetName() << "의 공격! " << P_dam << "의 피해" << endl;
			Sleep(500);
			if (monster->GetHealth() <= 0)
			{
				cout << monster->GetName() << "의 남은 체력 0 " << endl;
			}
			else
			{
				cout << monster->GetName() << "의 남은 체력 " << monster->GetHealth() << endl;
			}
		}
		else if (randomValue >= 95 && randomValue <= 99)
		{
			system("cls");
			//player->UseItem(); // 플레이어 무조건 선턴. 아이템 먼저 사용.
			//플레이어 공격
			int PC_dam = player->GetRandTotalAttack() * 1.6;
			monster->TakeDamage(PC_dam);
			printPlayer();

			cout << player->GetName() << "의 " << red << "!!크리티컬 공격!!" << white << PC_dam << "의 피해" << endl;
			Sleep(500);
			if (monster->GetHealth() <= 0)
			{
				cout << monster->GetName() << "의 남은 체력 0 " << endl;
			}
			else
			{
				cout << monster->GetName() << "의 남은 체력 " << monster->GetHealth() << endl;
			}
		}

		player->UseItem(); // 플레이어 무조건 선턴. 아이템 먼저 사용.
		Sleep(2000);

		if (monster->GetHealth() <= 0) // 몬스터가 공격하기 전 이미 피가 0 이하면 전투 종료.
		{
			break;
		}

		system("cls");

		switch (monster->GetSpecies())
		{
		case 1:
			printGoblin();
			break;
		case 2:
			printTroll();
			break;
		case 3:
			printOrc();
			break;
		default:
			break;
		}
		Sleep(100);
		system("cls");
		//몬스터 공격
		int mon_dam = monster->GetTotalAttack();
		player->TakeDamage(mon_dam);

		switch (monster->GetSpecies())
		{
		case 1:
			printGoblin();
			cout << endl << endl;
			break;
		case 2:
			printTroll();
			cout << endl << endl;
			break;
		case 3:
			printOrc();
			break;
		default:
			break;
		}
		cout << red << monster->GetName() << white << "의 공격! " << mon_dam << "의 피해" << endl;
		Sleep(500);
		if (player->GetHealth() <= 0)
		{
			cout << yellow << player->GetName() << white << "의 남은 체력 0 " << endl;
		}
		else
		{
			cout << yellow << player->GetName() << white << "의 남은 체력 " << player->GetHealth() << endl;
		}
		Sleep(2000);
		//useitem?
	}
	//둘 중 하나의 체력이 0 이하가 되어도 남은 공격 기회는 반드시 사용하는 경우를 수정.

	player->EndFight(); //인벤토리 아이템 사용 함수


	if (monster->GetHealth() <= 0) // 플레이어 승리 시 if 문 내에서 함수 종료후 메인으로
	{
		cout << "승리" << endl;
		player->LevelUp(); // 플레이어 레벨 업 함수 적용
		player->AddGold(monster->GetGold());
		PressAnyKey();
		//item 획득 함수;
	}
	else // 플레이어 패배 시 종료
	{
		system("cls");
		Stun_Player();
		cout << "                                       패배하였습니다." << endl;
		PressAnyKey();
		exit(0);
	}
}

void GameManager::bossbattle(Character* player, Monster* bossmonster)
{
	player->StartFight();
	for (int i = 0; i < 3; i++)
	{
		system("cls");
		BossStanding3();
		cout << "          보스 몬스터 출현!" << endl;
		Sleep(50);
		system("cls");
		BossStanding4();
		cout << "          보스 몬스터 출현!" << endl;
		Sleep(50);
	}
	system("cls");
	BossStanding3();
	cout << "          보스 몬스터 출현!" << endl;
	Sleep(1000);

	while (1)
	{
		system("cls");
		BossStanding2();
		cout << "아무키나 입력시 보스전에 돌입합니다" << endl;
		Sleep(1000);
		if (_kbhit()) {
			_getch(); // 키 입력을 받음 (입력된 키는 무시)
			break;
		}
		system("cls");
		BossStanding1();
		cout << "아무키나 입력시 보스전에 돌입합니다" << endl;
		Sleep(1000);
		if (_kbhit()) {
			_getch(); // 키 입력을 받음 (입력된 키는 무시)
			break;
		}
	}

	while ((player->GetHealth() > 0) && (bossmonster->GetHealth() > 0))
	{
		//player->UseItem();  // 플레이어 무조건 선턴. 아이템 먼저 사용.
		system("cls");
		Hit_Boss();
		Sleep(100);
		system("cls");
		Hit_Boss();
		Sleep(10);
		system("cls");
		Sleep(150);
		Hit_Boss();

		int randomValue = rand() % 100;

		if (randomValue >= 0 && randomValue <= 94)
		{
			system("cls");
			//player->UseItem(); // 플레이어 무조건 선턴. 아이템 먼저 사용.
			//플레이어 공격
			int b_P_dam = player->GetRandTotalAttack();
			monster->TakeDamage(b_P_dam);
			printPlayer();

			cout << player->GetName() << "의 공격! " << b_P_dam << "의 피해" << endl;
			Sleep(500);
			if (monster->GetHealth() <= 0)
			{
				cout << monster->GetName() << "의 남은 체력 0 " << endl;
			}
			else
			{
				cout << monster->GetName() << "의 남은 체력 " << monster->GetHealth() << endl;
			}
		}
		else if (randomValue >= 95 && randomValue <= 99)
		{
			system("cls");
			//player->UseItem(); // 플레이어 무조건 선턴. 아이템 먼저 사용.
			//플레이어 공격
			float b_PC_dam = player->GetRandTotalAttack() * 1.6;
			monster->TakeDamage(b_PC_dam);
			printPlayer();

			cout << player->GetName() << "의 " << red << "!!크리티컬 공격!!" << white << PC_dam << "의 피해" << endl;
			Sleep(500);
			if (monster->GetHealth() <= 0)
			{
				cout << monster->GetName() << "의 남은 체력 0 " << endl;
			}
			else
			{
				cout << monster->GetName() << "의 남은 체력 " << monster->GetHealth() << endl;
			}
		}
		player->UseItem(); // 플레이어 무조건 선턴. 아이템 먼저 사용.
		Sleep(2000);

		if (bossmonster->GetHealth() <= 0) // 몬스터가 공격하기 전 이미 피가 0 이하면 전투 종료.
		{
			break;
		}

		//보스 몬스터 공격
		system("cls");
		Attack_Boss2();
		Sleep(100);
		Attack_Boss1();

		int B_dam = bossmonster->GetAttack();
		cout << bossmonster->GetName() << "의 공격! " << B_dam << "의 피해" << endl;
		Sleep(500);
		player->TakeDamage(B_dam);
		if (player->GetHealth() <= 0)
		{
			cout << player->GetName() << "의 남은 체력 0 " << endl;
		}
		else
		{
			cout << player->GetName() << "의 남은 체력 " << player->GetHealth() << endl;
		}
		Sleep(2000);
	}

	player->EndFight();
	if (bossmonster->GetHealth() <= 0)
	{
		system("cls");
		Stun_Boss();
		cout << "승리" << endl;
		PressAnyKey();
		system("cls");
		//item 획득 함수;
		//골드 획득 함수;
		int gold = 0;
		player->SetGold(gold);
		EndingPhase();// 엔딩 문구
		PressAnyKey();
		exit(0);
	}
	else
	{
		system("cls");
		Stun_Player();
		cout << "                                       패배하였습니다." << endl;
		PressAnyKey();
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
