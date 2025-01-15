#pragma once
#include <iostream>
#include <string>

using namespace std;

//아이템
class Item
{
protected:
    string name;
    int weight;
    int price;
    int attack;
    int health;
    bool isUsed = false;

public:
    Item(const string& name, int weight, int price, int attack, int health)
        : name(name), weight(weight), price(price), attack(attack), health(health) {
    }

    const string& GetName() { return this->name; }
    int GetWeight() const { return weight; }
    int GetPrice() const { return price; }
    virtual int GetAttack() { return attack; }  //공격력 리턴
    virtual int GetHealth() { return health; }  //체력 리턴
    virtual bool IsUsed() { return isUsed; }
    virtual void UseItem() { return; } //사용 효과
    virtual void StartFight() { return; } //전투 시작시
    virtual void EndFight() { return; } //전투 종료시
    virtual ~Item() {}
};
