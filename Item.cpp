#include <iostream>
#include <string>

using namespace std;

//아이템
class Item 
{
private:
    string name;
    int weight;
    int price;

public:
    Item(const string& name, int weight, int price)
        : name(name), weight(weight), price(price) {}
    
    const string& GetName() { return this->name; }
    virtual ~Item() {};
};

//장비아이템
class EquipmentItem : public Item
{
private:
    int attack;
    int defense;
public:
    EquipmentItem(const string& name, int weight, int price, int attack, int defense)
        : Item(name, weight, price), attack(attack), defense(defense) {}
    virtual int GetAttack() { return attack; }   //공격력 리턴
    virtual int GeDefense() { return defense; }  //방어력 리턴
    
    // 발동 효과가 있을때 자식 클래스에 추가
    /*virtual void Used() {};*/
};

//소비아이템
class ConsumableItem : public Item
{
protected:
    int number;
public:
    ConsumableItem(const string& name, int weight, int price, int number)
        :Item(name, weight, price), number(number) {}
    virtual void Use() {};
    virtual int GetNumber() { return number; } //횟수 리턴
};

class Sword40 : public EquipmentItem
{
public:
    Sword40()
        : EquipmentItem("무게 4, 공격력 30인 검", 4/*weight*/, 50/*price*/, 30/*attack*/, 0/*defense*/) {}
};

class Potion10 : public ConsumableItem
{
public:
    Potion10()
        : ConsumableItem("체력 10 회복 일회용 포션", 1/*weight*/, 10/*price*/, 1/*number*/) { }
    void Use()
    {
        if (hp <= 10) 
        {
            hp += 10; //체력 10 회복
            number -= 1;
        }
    }
};

