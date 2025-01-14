#pragma once

#pragma region OriginalHeader
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>
#pragma endregion

#pragma region AddedHeader
#include "../headerFile/GameManager.h"
#include "../headerFile/Character.h"
#include "../headerFile/Item.h"
#include "../headerFile/Monster.h"
#include "../headerFile/Orc.h"
#include "../headerFile/Troll.h"
#include "../headerFile/Goblin.h"
#include "../headerFile/BossMonster.h"
#include "../headerFile/Shop.h"
#pragma endregion

using namespace std;


#pragma region GlobalVariable
/*
GameManager* GameManager::instance = nullptr;
Character* Character::instance = nullptr;
Shop* Shop::instance = nullptr;
*/
#pragma endregion

int main() {
	GameManager* gameManager = GameManager::GetInstance();
	//
	Character* player = Character::GetInstance();
	string playerName = player->NameValidation();
	Sleep(500);
	player->SetName(playerName);

	//player->NameValidation();
	//player->GetInstance();//Character* player = Character::GetInstance(); // 캐릭터 생성 로직 변경 필요 혹은 물어보기
	//cout << player->GetLevel();
	//Monster* monster = new Monster;
	//BossMonster* bossmonster = new BossMonster;
	int stage = 1;
	while (player->GetLevel() != 10) {
		int ncnt = 0;
		int selectStage = 0;
		Sleep(2000);

		while (ncnt == 0)
		{
			system("cls");
			cout << "================================" << endl;
			cout << "inGame" << endl;
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

				Monster* monster = new Monster;
				gameManager->generateMonster();
				gameManager->battle(player, monster);
				ncnt++;
				stage++;
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
				Sleep(3000);
			}
			else
			{
				cout << "다시 입력해주세요. " << endl;
				Sleep(1000);
				system("cls");
			}
			Sleep(500);
		}

		///////////////////////////////////////////////보스
		if (player->GetLevel() == 10)
		{
			while (ncnt == 0)
			{
				cout << "================================" << endl;
				cout << "inGame" << endl;
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

					BossMonster* bossmonster = new BossMonster;
					gameManager->generateBossMonster();
					gameManager->bossbattle(player, bossmonster);
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
	return 0;
}

//int main()
//{
//    /*GameManager* gameManager = GameManager::GetInstance();
//    Character* character = Character::GetInstance();
//    */
//    //Shop* shop = Shop::GetInstance();
//    // 게임 매니저가 처리하는 부분.
//    // 메인 루프 속에서 게임의 진행이 처리
//    
//    ///
//    /*
//    Item item_01 = Item();
//    Item item_02 = Item();
//    Item item_03 = Item();
//    */
//    for (int i = 0; i < 3; i++)
//    {
//        //Shop 에 만들어진 아이템을 집어넣는 기능. 혹은 shop 생성 당시에 아이템을 바로 넣을 것.//
//    }
//    int stage = 1;
//
//    ///
//
//    // 테스트용 변수
//    int time = 0;
//    // 테스트용 루프 
//    while (1)
//    {
//        cout << "================================" << endl;
//        cout << "inGame" << endl;
//        cout << "진행 시간 : " << time << endl;
//        cout << "현재 스테이지 : " << stage << endl;
//        cout << "================================" << endl;
//        
//        cout << "할 행동을 고르시오." << endl;
//        cout << "1 : 전투   2 : 상점   3 : 다른 거" << endl;
//        //분기 생성
//        //1. 전투 2. 상점. 3. ~~~
//        //if 1이면....
//        int selectStage = 0;
//        cin >> selectStage;
//        if (selectStage == 1)
//        {
//            //플레이어 레벨 가져오기
//            //int characterLevel = character.getLevel();
//
//            //몬스터 생성
//            //ex) generateMonster();
//
//            //배틀
//            //GameManager,battle(character)
//            cout << "1번 선택" << endl;
//
//            Sleep(1000);
//            cout << "몬스터와 조우!" << endl;
//
//            Sleep(1000);
//            cout << "캐릭터가 몬스터에게 10의 데미지!" << endl;
//
//            Sleep(1000);
//            cout << "몬스터가 캐릭터에게 20의 데미지!" << endl;
//        }
//        else if (selectStage == 2)
//        {
//            //else if 2 이면..
//            // //while문으로 한번 더...
//
//            //여기서 다시 분기문
//            //index 변수에 입력해서 1 ~ n까지의 아이템 인덱스 입력해서 뭘 살지 입력하고,
//            // 플레이어의 골드값과 아이템의 값을 비교하여 살 수 있는지 아닌지 결정
//            cout << "2번 선택" << endl;
//
//            Sleep(1000);
//            cout << "상점 오픈!" << endl;
//            //shop의 display 함수 실행
//
//            cout << "1번 항목 : asd 가격 : 123" << endl;
//            cout << "2번 항목 : qwe 가격 : 234" << endl;
//            cout << "3번 항목 : zxc 가격 : 345" << endl;
//            Sleep(1000);
//        }
//        else
//        {
//            cout << "다른거 선택" << endl;
//
//        }
//
//
//        Sleep(1000);
//
//        system("cls");
//        time++;
//    }
//
//
//
//    return 0;
//}