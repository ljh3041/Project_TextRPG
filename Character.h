#pragma once
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

//Singleton Pattern
class Character
{
private:
	static Character* instance;
	Character();
    ~Character();
    
    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int experience;    
    int gold;

    vector<Item*> inventory;


	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

public:
    static Character* GetInstance(const string& characterName); // �̸������� ���� �ҽ����Ϸ� �ڵ� �̵�
    static void ReleaseInstance();
    static bool IsValidName(const string& characterName); // �̸� ���� �Լ�
    
    void LevelUp();
    void UseItem(int index);
    void VisitShop();
    void DisplayStatus();
};