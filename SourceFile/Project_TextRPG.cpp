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
	int stageguide = 0;
	gameManager->tutorialPhase();


	while (1)
	{
		stageguide = gameManager->firstPhase();

		if (stageguide == 1)
		{
			gameManager->BattlePhase();

		}
		else if (stageguide == 2)
		{
			gameManager->StorePhase();
		}
		else if (stageguide == 3)
		{
			gameManager->StatusPhase();
		}
		else
		{
			cout << "다시 입력해주세요. " << endl;
			PressAnyKey();
		}
	
	}
	return 0;
}
