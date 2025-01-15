#pragma once
#include "Item.h"

//기본 검
class Sword10 : public Item
{
public:
    Sword10()
        : Item("무게 1, 공격력 10인 검", 1/*weight*/, 10/*price*/, 20/*attack*/, 0/*health*/) {
    }
};

class Sword20 : public Item
{
public:
    Sword20()
        : Item("무게 1, 공격력 20인 검", 1/*weight*/, 20/*price*/, 20/*attack*/, 0/*health*/) {
    }
};

class Sword30 : public Item
{
public:
    Sword30()
        : Item("무게 2, 공격력 20인 검", 2/*weight*/, 30/*price*/, 30/*attack*/, 0/*health*/) {
    }
};

class Sword40 : public Item
{
public:
    Sword40()
        : Item("무게 2, 공격력 40인 검", 2/*weight*/, 40/*price*/, 40/*attack*/, 0/*health*/) {
    }
};

class Sword50 : public Item
{
public:
    Sword50()
        : Item("무게 3, 공격력 50인 검", 3/*weight*/, 50/*price*/, 50/*attack*/, 0/*health*/) {
    }
};


//레벨 비례검
class ScalingSword10 : public Item
{
public:
    ScalingSword10()
        : Item("무게 3, 공격력이 레벨*5인 검", 3/*weight*/, 60/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetAttack();
};

class ScalingSword20 : public Item
{
public:
    ScalingSword20()
        : Item("무게 3, 공격력이 레벨*10인 검", 3/*weight*/, 70/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetAttack();
};

class ScalingSword30 : public Item
{
public:
    ScalingSword30()
        : Item("무게 4, 공격력이 레벨*15인 검", 4/*weight*/, 80/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetAttack();
};

class ScalingSword40 : public Item
{
public:
    ScalingSword40()
        : Item("무게 4, 공격력이 레벨*20인 검", 4/*weight*/, 90/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetAttack();
};

class ScalingSword50 : public Item
{
public:
    ScalingSword50()
        : Item("무게 5, 공격력이 레벨*25인 검", 5/*weight*/, 100/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetAttack();
};


//흡혈단검
class VampiricDagger10 : public Item
{
public:
    VampiricDagger10()
        :Item("데미지의 10%만큼 흡혈하는 무게 1, 공격력 2 단검", 1/*weight*/, 20/*price*/, 2/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class VampiricDagger20 : public Item
{
public:
    VampiricDagger20()
        :Item("데미지의 20%만큼 흡혈하는 무게 1, 공격력 4 단검", 1/*weight*/, 40/*price*/, 4/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class VampiricDagger30 : public Item
{
public:
    VampiricDagger30()
        :Item("데미지의 30%만큼 흡혈하는 무게 2, 공격력 6 단검", 2/*weight*/, 60/*price*/, 6/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class VampiricDagger40 : public Item
{
public:
    VampiricDagger40()
        :Item("데미지의 40%만큼 흡혈하는 무게 2, 공격력 8 단검", 2/*weight*/, 80/*price*/, 8/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class VampiricDagger50 : public Item
{
public:
    VampiricDagger50()
        :Item("데미지의 50%만큼 흡혈하는 무게 2, 공격력 10 단검", 2/*weight*/, 100/*price*/, 10/*attack*/, 0/*health*/) {
    }
    void UseItem();
};



//체력도
class HP_Blade1 : public Item
{
private:
    int count = 0;
public:
    HP_Blade1()
        :Item("4번째 공격에 나의 현재체력의 1%의 추가 피해를 주는 무게2, 체력 10의 도", 2/*weight*/, 30/*price*/, 0/*attack*/, 10/*health*/) {
    }
    int GetAttack();
    void UseItem();
};

class HP_Blade2 : public Item
{
private:
    int count = 0;
public:
    HP_Blade2()
        :Item("4번째 공격에 나의 현재체력의 2%의 추가 피해를 주는 무게2, 체력 20의 도", 2/*weight*/, 40/*price*/, 0/*attack*/, 20/*health*/) {
    }
    int GetAttack();
    void UseItem();
};

class HP_Blade3 : public Item
{
private:
    int count = 0;
public:
    HP_Blade3()
        :Item("4번째 공격에 나의 현재체력의 3%의 추가 피해를 주는 무게2, 체력 30의 도", 2/*weight*/, 50/*price*/, 0/*attack*/, 30/*health*/) {
    }
    int GetAttack();
    void UseItem();
};

class HP_Blade4 : public Item
{
private:
    int count = 0;
public:
    HP_Blade4()
        :Item("4번째 공격에 나의 현재체력의 4%의 추가 피해를 주는 무게2, 체력 40의 도", 2/*weight*/, 60/*price*/, 0/*attack*/, 40/*health*/) {
    }
    int GetAttack();
    void UseItem();
};

class HP_Blade5 : public Item
{
private:
    int count = 0;
public:
    HP_Blade5()
        :Item("3번째 공격에 나의 현재체력의 5%의 추가 피해를 주는 무게2, 체력 50의 도", 2/*weight*/, 70/*price*/, 0/*attack*/, 50/*health*/) {
    }
    int GetAttack();
    void UseItem();
};


//기본 갑옷
class Armor10 : public Item
{
public:
    Armor10()
        : Item("무게 2, 체력 100인 갑옷", 2/*weight*/, 10/*price*/, 0/*attack*/, 100/*health*/) {
    }
};

class Armor20 : public Item
{
public:
    Armor20()
        : Item("무게 2, 체력 200인 갑옷", 2/*weight*/, 20/*price*/, 0/*attack*/, 200/*health*/) {
    }
};

class Armor30 : public Item
{
public:
    Armor30()
        : Item("무게 3, 체력 300인 갑옷", 3/*weight*/, 30/*price*/, 0/*attack*/, 300/*health*/) {
    }
};

class Armor40 : public Item
{
public:
    Armor40()
        : Item("무게 3, 체력 400인 갑옷", 3/*weight*/, 40/*price*/, 0/*attack*/, 400/*health*/) {
    }
};

class Armor50 : public Item
{
public:
    Armor50()
        : Item("무게 3, 체력 500인 갑옷", 3/*weight*/, 50/*price*/, 0/*attack*/, 500/*health*/) {
    }
};

//레벨비례 갑옷
class ScalingArmor10 : public Item
{
public:
    ScalingArmor10()
        : Item("무게 3, 체력이 레벨*10인 갑옷", 3/*weight*/, 60/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetHealth();
};

class ScalingArmor20 : public Item
{
public:
    ScalingArmor20()
        : Item("무게 4, 체력이 레벨*20인 갑옷", 4/*weight*/, 70/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetHealth();
};

class ScalingArmor30 : public Item
{
public:
    ScalingArmor30()
        : Item("무게 4, 체력이 레벨*30인 갑옷", 4/*weight*/, 80/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetHealth();
};

class ScalingArmor40 : public Item
{
public:
    ScalingArmor40()
        : Item("무게 5, 체력이 레벨*40인 갑옷", 5/*weight*/, 90/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetHealth();
};

class ScalingArmor50 : public Item
{
public:
    ScalingArmor50()
        : Item("무게 5, 체력이 레벨*50인 갑옷", 5/*weight*/, 100/*price*/, 0/*attack*/, 0/*health*/) {
    }
    int GetHealth();
};

//회복 갑옷
class HealingArmor2 : public Item
{
private:
    int count = 0;
public:
    HealingArmor2()
        :Item("전투종료시 전체 체력의 2%를 회복하는 무게 1, 체력 20 방어구", 1/*weight*/, 20/*price*/, 0/*attack*/, 20/*health*/) {
    }
    void EndFight();
};

class HealingArmor4 : public Item
{
private:
    int count = 0;
public:
    HealingArmor4()
        :Item("전투종료시 전체 체력의 4%를 회복하는 무게 2, 체력 40 방어구", 2/*weight*/, 40/*price*/, 0/*attack*/, 40/*health*/) {
    }
    void EndFight();
};

class HealingArmor6 : public Item
{
private:
    int count = 0;
public:
    HealingArmor6()
        :Item("전투종료시 전체 체력의 6%를 회복하는 무게 2, 체력 60 방어구", 2/*weight*/, 60/*price*/, 0/*attack*/, 60/*health*/) {
    }
    void EndFight();
};

class HealingArmor8 : public Item
{
private:
    int count = 0;
public:
    HealingArmor8()
        :Item("전투종료시 전체 체력의 8%를 회복하는 무게 3, 체력 80 방어구", 3/*weight*/, 80/*price*/, 0/*attack*/, 80/*health*/) {
    }
    void EndFight();
};

class HealingArmor10 : public Item
{
private:
    int count = 0;
public:
    HealingArmor10()
        :Item("전투종료시 전체 체력의 10%를 회복하는 무게 3, 체력 100 방어구", 3/*weight*/, 100/*price*/, 0/*attack*/, 100/*health*/) {
    }
    void EndFight();
};
