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
    int basicAttack;
    int extraAttack;
    int totalAttack;
    int experience;
    int expForLevelUp;
    int gold;
    int maxLevel;

    vector<Item*> inventory;

    int inventoryWeight;
    int maxInventoryWeight;

    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;

public:
    static Character* GetInstance();
    static void ReleaseInstance();

    void NameValidation(); // 이름 검증
    void DisplayStatus();
    void LevelUp();   
    void TakeDamage(int damage);
    void Healing(int heal);

    void SetGold(int settleGold);  
    void SetInventoryWeight(int weight);

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
        return totalAttack;
    }

    string GetName() const
    {
        return name;
    }


    int GetGold() const
    {
        return gold;
    }

   

    // 아이템 관련 함수
    int GetItemAttack();
    int GetItemHealth();
    void UseItem();
    void StartFight();
    void EndFight();
    int GetTotalAttack();
    int GetTotalHealth();
    
    
    int GetInventoryWeight();
    int GetMaxInventoryWeight();
    void AddToInventory(Item* item);
    vector<Item*> GetInventory();
    void remove_from_inventory(Item* item);
};

