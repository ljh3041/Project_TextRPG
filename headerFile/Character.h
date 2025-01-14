#pragma once
#include <iostream>

#include <string>
#include <algorithm>
#include <cctype>
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
    static Character* GetInstance();
    static void ReleaseInstance();

    string NameValidation(); // 이름 검증
    void DisplayStatus();
    void LevelUp();
    //void UseItem(int index);
    //void VisitShop();


    //✨ update  
    int GetLevel() const
    {

        return level;
    }
    int GetHealth() const
    {
        return health;
    }
    int GetMaxHealth() const
    {
        return maxHealth;
    }
    int GetAttack() const
    {
        return attack;
    }
    string GetName() const
    {

        return name;
    }
    void TakeDamage(int damage);
    void Healing(int heal);

    int GetGold() const
    {
        return gold;
    }

    void SetGold(int settleGold);

    // 아이템 관련 함수
    int GetItemAttack();

    int GetItemHealth();

    void UseItem();

    void StartFight();

    void EndFight();
};

