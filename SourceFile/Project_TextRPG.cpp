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
GameManager* GameManager::instance = nullptr;
Character* Character::instance = nullptr;
Shop* Shop::instance = nullptr;
#pragma endregion


int main()
{
    GameManager* gameManager = GameManager::GetInstance();
    Character* character = Character::GetInstance();
    Shop* shop = Shop::GetInstance();
    // 게임 매니저가 처리하는 부분.
    // 메인 루프 속에서 게임의 진행이 처리
    
    ///

    Item item_01 = Item();
    Item item_02 = Item();
    Item item_03 = Item();
    for (int i = 0; i < 3; i++)
    {
        //Shop 에 만들어진 아이템을 집어넣는 기능. 혹은 shop 생성 당시에 아이템을 바로 넣을 것.//
        /*
        shop.vector.push_back(item01);
        */
    }
    int stage = 1;




    ///

    // 테스트용 변수
    int time = 0;
    // 테스트용 루프 
    while (1)
    {
        cout << "================================" << endl;
        cout << "inGame" << endl;
        cout << "진행 시간 : " << time << endl;
        cout << "stage : " << stage << endl;
        cout << "================================" << endl;
        //분기 생성
        //if(stage < 10) // 보스 스테이지 이전이면
        // {
        //     일반 몬스터와의 전투
        // }
        //1. 전투 2. 상점. 3. ~~~
        //if 1이면....

        //플레이어 레벨 가져오기
        //int characterLevel = character.getLevel();
        
        //몬스터 생성
        //ex) generateMonster();
        
        //배틀
        //GameManager,battle(character)

        //else if 2 이면..
        // //while문으로 한번 더...
        //shop의 display 함수 실행
        //여기서 다시 분기문
        //index 변수에 입력해서 1 ~ n까지의 아이템 인덱스 입력해서 뭘 살지 입력하고,
        // 플레이어의 골드값과 아이템의 값을 비교하여 살 수 있는지 아닌지 결정


        Sleep(1000);
        stage++;
        system("cls");
        time++;
    }



    return 0;
}