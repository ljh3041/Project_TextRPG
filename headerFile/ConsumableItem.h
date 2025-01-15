#pragma once
#include "Item.h"

class potion50 : public Item
{
public:
    potion50()
        : Item("체력이 100 이하일 때 체력 50을 회복하는 포션", 1/*weight*/, 5/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class potion100 : public Item
{
public:
    potion100()
        : Item("체력이 100 이하일 때 체력 100을 회복하는 포션", 1/*weight*/, 10/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class potion300 : public Item
{
public:
    potion300()
        : Item("체력이 100 이하일 때 체력 300을 회복하는 포션", 1/*weight*/, 30/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class potion600 : public Item
{
public:
    potion600()
        : Item("체력이 100 이하일 때 체력 600을 회복하는 포션", 1/*weight*/, 60/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

//비율포션
class potionQuarter : public Item
{
public:
    potionQuarter()
        : Item("체력이 25% 이하일 때 체력 25%를 회복하는 포션", 1/*weight*/, 35/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class potionHalf : public Item
{
public:
    potionHalf()
        : Item("체력이 50% 이하일 때 체력 50%를 회복하는 포션", 1/*weight*/, 70/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class potionFull : public Item
{
public:
    potionFull()
        : Item("체력이 10% 이하일 때 체력 100%를 회복하는 포션", 1/*weight*/, 140/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};