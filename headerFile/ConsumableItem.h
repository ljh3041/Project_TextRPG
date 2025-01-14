#pragma once
#include "Item.h"

class potion100 : public Item
{
public:
    potion100()
        : Item("체력이 100 이하일 때 체력 100을 회복하는 포션", 1/*weight*/, 10/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};

class potionHalf : public Item
{
public:
    potionHalf()
        : Item("체력이 50% 이하일 때 체력 50%를 회복하는 포션", 1/*weight*/, 40/*price*/, 0/*attack*/, 0/*health*/) {
    }
    void UseItem();
};