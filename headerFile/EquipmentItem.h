#pragma once
#include "Item.h"

class Sword40 : public Item
{
public:
    Sword40()
        : Item("무게 4, 공격력 40인 검", 4/*weight*/, 40/*price*/, 40/*attack*/, 0/*health*/) {
    }
};

class ScalingSword3 : public Item
{
public:
    ScalingSword3()
        : Item("무게 3, 공격력이 레벨*3인 검", 3/*weight*/, 60/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetAttack();
};

class VampiricDagger : public Item
{
public:
    VampiricDagger()
        :Item("데미지의 30%만큼 흡혈하는 무게 1, 공격력 10 단검", 1/*weight*/, 30/*price*/, 10/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class HP_Blade4 : public Item
{
private:
    int count = 0;
public:
    HP_Blade4()
        :Item("4번째 공격에 나의 현재체력의 5%의 추가 피해를 주는 무게2, 체력 50의 도", 2/*weight*/, 70/*price*/, 0/*attack*/, 50/*health*/) {
    }
    int GetAttack();
    void UseItem();
};

class HealingArmor : public Item
{
private:
    int count = 0;
public:
    HealingArmor()
        :Item("전투종료시 전체 체력의 10%를 회복하는 체력 100 방어구", 3/*weight*/, 100/*price*/, 0/*attack*/, 100/*health*/) {
    }
    void EndFight();
};