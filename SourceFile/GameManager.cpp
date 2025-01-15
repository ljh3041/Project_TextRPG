#include "../headerFile/GameManager.h"
#include "../headerFile/GraphicInterface.h"
#include <windows.h>
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
	//showTeamName();
	//showGameName();
	Character::GetInstance()->NameValidation();
	Sleep(500);
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
	Shop::GetInstance()->InitializeShop();
	player->StartFight(); //인벤토리 아이템 사용 함수
	while ((player->GetHealth() > 0) && (monster->GetHealth() > 0)) // 캐릭터.h에 gethealth 추가
	{
		player->UseItem(); // 플레이어 무조건 선턴. 아이템 먼저 사용.
		//플레이어 공격
		printPlayer();
		cout << player->GetName() << "의 공격! " << player->GetTotalAttack() << "의 피해" << endl;
		Sleep(500);
		monster->TakeDamage(player->GetTotalAttack());
		if (monster->GetHealth() <= 0)
		{
			cout << monster->GetName() << "의 남은 체력 0 " << endl;
		}
		else 
		{
			cout << monster->GetName() << "의 남은 체력 " << monster->GetHealth() << endl;
		}
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
		if(player->GetHealth() <= 0)
		{ 
			cout << player->GetName() << "의 남은 체력 0 " << endl;
		}
		else
		{
			cout << player->GetName() << "의 남은 체력 " << player->GetHealth() << endl;
		}
		Sleep(1000);
		//useitem?
	}
	//둘 중 하나의 체력이 0 이하가 되어도 남은 공격 기회는 반드시 사용하는 경우를 수정.

	player->EndFight(); //인벤토리 아이템 사용 함수


	if (monster->GetHealth() <= 0) // 플레이어 승리 시 if 문 내에서 함수 종료후 메인으로
	{
		cout << "승리" << endl;
		player->LevelUp(); // 플레이어 레벨 업 함수 적용
		player->SetGold(monster->GetGold());
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
		cout << player->GetName() << "의 공격! " << player->GetTotalAttack() << "의 피해" << endl;
		Sleep(500);
		bossmonster->TakeDamage(player->GetTotalAttack());
		if (bossmonster->GetHealth() <= 0)
		{
			cout << bossmonster->GetName() << "의 남은 체력 0 " << endl;
		}
		else
		{
			cout << bossmonster->GetName() << "의 남은 체력 " << bossmonster->GetHealth() << endl;
		}
		Sleep(1000);

		if (bossmonster->GetHealth() <= 0) // 몬스터가 공격하기 전 이미 피가 0 이하면 전투 종료.
		{
			break;
		}

		//보스 몬스터 공격
		cout << bossmonster->GetName() << "의 공격! " << bossmonster->GetAttack() << "의 피해" << endl;
		Sleep(500);
		player->TakeDamage(bossmonster->GetAttack());
		if(player->GetHealth() <= 0)
		{ 
			cout << player->GetName() << "의 남은 체력 0 " << endl;
		}
		else
		{
			cout << player->GetName() << "의 남은 체력 " << player->GetHealth() << endl;
		}
		Sleep(1000);
	}
	player->EndFight();
	if (bossmonster->GetHealth() <= 0)
	{
		cout << "승리" << endl; // 엔딩 문구 추가
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

void GameManager::showTeamName()
{

	const char* asciiArt = R"( 
                                          _____                         
                                         |_   _|                        
                                           | |    ___   __ _  _ __ ___  
                                           | |   / _ \ / _` || '_ ` _ \ 
                                           | |  |  __/| (_| || | | | | |
                                           \_/   \___| \__,_||_| |_| |_|)";

	const char* asciiArt2 = R"(   
            
        	  _      _            _    _                                      _             _           
                 | |    (_)          | |  | |                                    | |           | |          
          __ _   | |__   _  _ __   __| |  | | __ _ __    ___  __      __ _ __    | |_   ___    | |__    ___ 
         / _` |  | '_ \ | || '__| / _` |  | |/ /| '_ \  / _ \ \ \ /\ / /| '_ \   | __| / _ \   | '_ \  / _ \
        | (_| |  | |_) || || |   | (_| |  |   < | | | || (_) | \ V  V / | | | |  | |_ | (_) |  | |_) ||  __/
         \__,_|  |_.__/ |_||_|    \__,_|  |_|\_\|_| |_| \___/   \_/\_/  |_| |_|   \__| \___/   |_.__/  \___|  )";

	const char* asciiArt3 = R"(
   
      __   _____                      _                                           _    _                         
     /  | |  _  |                    | |                                         | |  | |                        
     `| |  \ V /    ___  _ __ ___    | |  ___   _ __    __ _     __ _  _ __    __| |  | |__    __ _ __   __  ___ 
      | |  / _ \   / __|| '_ ` _ \   | | / _ \ | '_ \  / _` |   / _` || '_ \  / _` |  | '_ \  / _` |\ \ / / / _ \
     _| |_| |_| | | (__ | | | | | |  | || (_) || | | || (_| |  | (_| || | | || (_| |  | | | || (_| | \ V / |  __/
     \___/\_____/  \___||_| |_| |_|  |_| \___/ |_| |_| \__, |   \__,_||_| |_| \__,_|  |_| |_| \__,_|  \_/   \___|
                                                        __/ |                                                    
                                                       |___/                                                     )";

	const char* asciiArt4 = R"(
                  
                                               _                          _    _   __         _ 
                                              | |                        | |  (_) / _|       | |
                  __   __  ___  _ __  _   _   | |__    ___   __ _  _   _ | |_  _ | |_  _   _ | |
                  \ \ / / / _ \| '__|| | | |  | '_ \  / _ \ / _` || | | || __|| ||  _|| | | || |
                   \ V / |  __/| |   | |_| |  | |_) ||  __/| (_| || |_| || |_ | || |  | |_| || |
                    \_/   \___||_|    \__, |  |_.__/  \___| \__,_| \__,_| \__||_||_|   \__,_||_|
                                       __/ |                                                    
                                      |___/                                                     
                  						    
  )";


	const char* asciiArt5 = R"(
       __               _                                         _  _    _              _         _      _    
      / _|             | |                                       (_)| |  | |            (_)       | |    | |   
     | |_   ___   __ _ | |_  _   _  _ __   ___  ___    __      __ _ | |_ | |__      ___  _   __ _ | |__  | |_  
     |  _| / _ \ / _` || __|| | | || '__| / _ \/ __|   \ \ /\ / /| || __|| '_ \    / _ \| | / _` || '_ \ | __| 
     | |  |  __/| (_| || |_ | |_| || |   |  __/\__ \    \ V  V / | || |_ | | | |  |  __/| || (_| || | | || |_  
     |_|   \___| \__,_| \__| \__,_||_|    \___||___/     \_/\_/  |_| \__||_| |_|   \___||_| \__, ||_| |_| \__| 
                                                                                             __/ |             
                                                                                            |___/              
)";
	const char* asciiArt6 = R"(
                        _                         _     __               _    _                         
                       | |                       | |   / _|             | |  | |                        
            ___   ___  | |  ___   _ __   ___   __| |  | |_   ___   __ _ | |_ | |__    ___  _ __  ___    
           / __| / _ \ | | / _ \ | '__| / _ \ / _` |  |  _| / _ \ / _` || __|| '_ \  / _ \| '__|/ __|   
          | (__ | (_) || || (_) || |   |  __/| (_| |  | |  |  __/| (_| || |_ | | | ||  __/| |   \__ \ _ 
           \___| \___/ |_| \___/ |_|    \___| \__,_|  |_|   \___| \__,_| \__||_| |_| \___||_|   |___/( )
                                                                                                     |/                                                                                                        
)";
	const char* asciiArt7 = R"(
                           _                                            _         _                      
                          | |                                          (_)       | |                     
         ___  _   _   ___ | |__      __ _  ___     __ _    _ __   __ _  _  _ __  | |__    ___  __      __
        / __|| | | | / __|| '_ \    / _` |/ __|   / _` |  | '__| / _` || || '_ \ | '_ \  / _ \ \ \ /\ / /
        \__ \| |_| || (__ | | | |  | (_| |\__ \  | (_| |  | |   | (_| || || | | || |_) || (_) | \ V  V / 
        |___/ \__,_| \___||_| |_|   \__,_||___/   \__,_|  |_|    \__,_||_||_| |_||_.__/  \___/   \_/\_/  
)";


	cout << asciiArt << endl;
	Sleep(1000);
	cout << asciiArt2 << endl;
	Sleep(1000);
	cout << asciiArt3 << endl;
	Sleep(1000);
	cout << asciiArt4 << endl;
	Sleep(1000);
	cout << asciiArt5 << endl;
	Sleep(1000);
	cout << asciiArt6 << endl;
	Sleep(1000);
	cout << asciiArt7 << endl;
	Sleep(1000);

	system("cls");
	
}

void GameManager::showGameName()
{

	const char* asciiArt = R"(

 _____                                         _       _____ ___  ___ _____     ______ ______  _____ 
|_   _|                                       | |     |_   _||  \/  ||_   _|    | ___ \| ___ \|  __ \
  | |    ___    ___    _ __ ___   _   _   ___ | |__     | |  | .  . |  | |      | |_/ /| |_/ /| |  \/
  | |   / _ \  / _ \  | '_ ` _ \ | | | | / __|| '_ \    | |  | |\/| |  | |      |    / |  __/ | | __ 
  | |  | (_) || (_) | | | | | | || |_| || (__ | | | |   | |  | |  | | _| |_  _  | |\ \ | |    | |_\ \
  \_/   \___/  \___/  |_| |_| |_| \__,_| \___||_| |_|   \_/  \_|  |_/ \___/ (_) \_| \_|\_|     \____/
                                                                                                     
                                                                                                     

)";
	cout << asciiArt << endl;
	Sleep(1000);

	PressAnyKey();
	system("cls");
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
