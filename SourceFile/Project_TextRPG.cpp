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
#include "../headerFile/Dragon.h"
#include "../headerFile/Shop.h"
#include "../headerFile/MyMath.h"
#pragma endregion

using namespace std;


#pragma region GlobalVariable

GameManager* gameManager = nullptr;
Character* player = nullptr;
Shop* shop = nullptr;

#pragma endregion

int main() {
	gameManager = GameManager::GetInstance();
	player = Character::GetInstance();
	shop = Shop::GetInstance();

	string playerName = player->NameValidation();
	Monster* enemy = GameManager::GetInstance()->getMonster();
	
	Sleep(500);
	player->SetName(playerName);
	PressAnyKey();


	int stage = 1;
	int stageguide = 0;


	while (1)
	{
		stageguide = gameManager->firstPhase();

		if (stageguide == 1)
		{
			cout << "1번 선택" << endl;
			Sleep(500);
			cout << "몬스터와 조우!" << endl;
			Sleep(500);

			if (stage < 10)
			{
				gameManager->generateMonster();
				gameManager->battle(player, GameManager::GetInstance()->getMonster());
				stage++;
			}
			else
			{
				//한번에 battle함수로만 컨트롤 하고, monster generate에서 bossmonster를 생성하는 것도 
				gameManager->generateBossMonster();
				gameManager->bossbattle(player, GameManager::GetInstance()->getMonster());
			}

		}
		else if (stageguide == 2)
		{
			cout << "2번 선택" << endl;
			Sleep(500);
			cout << "상점 오픈!" << endl;
			Sleep(500);

			gameManager->visitShop();
		}
		else if (stageguide == 3)
		{
			cout << "3번 선택" << endl;
			Sleep(500);
			cout << "상태보기" << endl;
			Sleep(500);

			gameManager->displayInventory(player);
			PressAnyKey();

		}
		else
		{
			cout << "다시 입력해주세요. " << endl;
			cout << "\n▶Press Anykey";
			PressAnyKey();
		}
	
	}
	return 0;
}
