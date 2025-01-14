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

public:
    Item(const string& name, int weight, int price)
        : name(name), weight(weight), price(price) {
    }

    const string& getName() { return this->name; }
    int getWeight() const { return weight; }
    int getPrice() const { return price; }
    virtual ~Item() {}
};

//장비아이템
class EquipmentItem : public Item
{
protected:
    int attack;
    int defense;
public:
    EquipmentItem(const string& name, int weight, int price, int attack, int defense)
        : Item(name, weight, price), attack(attack), defense(defense) {
    }
    virtual int getAttack() { return attack; }   //공격력 리턴
    virtual int getDefense() { return defense; }  //방어력 리턴

    // 사용 효과
    /*void useItem() {};*/
    // 시작시 효과
    /*void startFight() {};*/
    // 종료시 효과
    /*void endFight() {};*/
};

//소비아이템
class ConsumableItem : public Item
{
protected:
    int number;
public:
    ConsumableItem(const string& name, int weight, int price, int number)
        :Item(name, weight, price), number(number) {
    }
    virtual void useItem() {} //사용 효과
    virtual int getNumber() { return number; } //횟수 리턴
};

/*
string Item::getName()
{
    return name;
}
*/