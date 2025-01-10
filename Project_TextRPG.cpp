#pragma once

#pragma region OriginalHeader
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>
#pragma endregion

#pragma region AddedHeader
#include "GameManager.h"
#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include "Orc.h"
#include "Troll.h"
#include "Goblin.h"
#include "BossMonster.h"
#include "Shop.h"
#pragma endregion

using namespace std;


#pragma region GlobalVariable
GameManager* GameManager::instance = nullptr;
#pragma endregion


int main()
{
    cout << "Main Loop" << endl;

    // 게임 매니저가 처리하는 부분.
    // 메인 루프 속에서 게임의 진행이 처리
    while (1)
    {
        cout << "inGame" << endl;
        Sleep(1000);
    }



    return 0;
}